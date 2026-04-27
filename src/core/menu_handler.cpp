#include "../../include/core/menu_handler.h"
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp> 
#include <vector>
#include <string>
#include <iomanip> 
#include <sstream>

// Structures for session tracking
struct Transaction { std::string type; std::string source; double amount; };
std::vector<Transaction> session_history; 
double total_in = 0.0, total_out = 0.0;

// Helper to lock decimals to 2 spots (No more .000000!)
std::string formatCurrency(double amount) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << amount;
    return "$" + ss.str();
}

void showTracker(std::string mode);
void showAccountingSheet();

void chooseTracker() {
    using namespace ftxui;
    int selected = 0;
    std::vector<std::string> options = { 
        " [1] 💰 REVENUE LOG     ", 
        " [2] 💸 EXPENSE LOG     ", 
        " [3] 📊 AUDIT LEDGER    " 
    };

    auto screen = ScreenInteractive::TerminalOutput();

    // ENABLE MOUSE SUPPORT IN MENU
    MenuOption menu_opt;
    menu_opt.on_enter = [&] { /* Triggers on double click/enter */ };
    
    auto menu = Menu(&options, &selected, menu_opt);
    
    auto btn = Button(" OPEN MODULE ", [&] { 
        if (selected == 0) showTracker("INCOME");
        else if (selected == 1) showTracker("EXPENSE");
        else showAccountingSheet();
    });

    auto renderer = Renderer(Container::Vertical({menu, btn}), [&] {
        return vbox({
            text(" F L U X   S Y S T E M S ") | bold | center | color(Color::DeepSkyBlue1),
            text("──────────────────────────────────────────────") | center | color(Color::DeepSkyBlue1),
            text(""), 
            vbox({
                text(""),
                text("  NAVIGATOR INTERFACE ") | bold | color(Color::MediumPurple1),
                text(""),
                menu->Render() | color(Color::Cyan1),
                text(""),
                btn->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White),
                text(""),
            }) | borderHeavy | color(Color::DeepSkyBlue1) | size(WIDTH, EQUAL, 55),
            text(""),
            text(" PRESS [Q] TO EMERGENCY EXIT ") | dim | center
        }) | center;
    });

    // Clean Exit Event Listener
    auto component = CatchEvent(renderer, [&](Event event) {
        if (event == Event::Character('q') || event == Event::Escape) {
            screen.Exit();
            return true;
        }
        return false;
    });

    screen.Loop(component);
}

void showTracker(std::string mode) {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();
    std::string amt = "", src = "";
    Color themeColor = (mode == "INCOME") ? Color::Cyan1 : Color::MediumPurple1;

    Component input_src = Input(&src, "Description/Source...");
    Component input_amt = Input(&amt, "0.00");

    auto log_btn = Button(" COMMIT TO LEDGER ", [&] {
        if(!amt.empty()){
            try {
                double value = std::stod(amt);
                session_history.push_back({mode, src, value});
                if(mode == "INCOME") total_in += value; else total_out += value;
                amt = ""; src = ""; // Reset for multiple entries
            } catch (...) {}
        }
    });
    auto back_btn = Button(" FINISH ", [&] { screen.Exit(); });

    auto renderer = Renderer(Container::Vertical({input_src, input_amt, log_btn, back_btn}), [&] {
        return vbox({
            text(" MODULE: " + mode) | bold | center | color(themeColor),
            separatorDouble() | color(themeColor),
            text(""),
            vbox({
                text(""),
                hbox(text("  ITEM/SOURCE : "), input_src->Render() | flex, text("  ")),
                text(""),
                separator() | dim,
                text(""),
                hbox(text("  AMOUNT ($)  : "), input_amt->Render() | flex, text("  ")),
                text(""),
            }) | border | color(themeColor),
            text(""),
            hbox({ log_btn->Render() | flex, back_btn->Render() | flex })
        }) | borderHeavy | color(themeColor) | center | size(WIDTH, EQUAL, 55);
    });

    screen.Loop(renderer);
}

void showAccountingSheet() {
    using namespace ftxui;
    auto screen = ScreenInteractive::TerminalOutput();
    auto back = Button(" CLOSE REPORT ", [&] { screen.Exit(); });

    auto renderer = Renderer(back, [&] {
        std::vector<std::vector<Element>> table_data = {
            { text(" CATEGORY ") | bold, text(" DESCRIPTION ") | bold, text(" AMOUNT ") | bold }
        };

        for (auto& t : session_history) {
            table_data.push_back({
                text(" " + t.type + " ") | color(t.type == "INCOME" ? Color::Cyan1 : Color::MediumPurple1),
                text(" " + t.source + " "),
                text(" " + formatCurrency(t.amount) + " ") | align_right
            });
        }

        auto table_render = Table(table_data);
        table_render.SelectAll().Border(LIGHT);
        table_render.SelectRow(0).Decorate(bgcolor(Color::DeepSkyBlue1));
        table_render.SelectColumn(1).Decorate(flex); 

        return vbox({
            text(" FINANCIAL AUDIT REPORT ") | bold | center | color(Color::Cyan1),
            separatorHeavy() | color(Color::DeepSkyBlue1),
            text(""),
            vbox({
                text(""),
                hbox({ text("  "), table_render.Render() | flex, text("  ") }),
                text(""),
                separator() | dim,
                text(""),
                vbox({
                    hbox(text("  TOTAL REVENUE: "), filler(), text(formatCurrency(total_in)) | color(Color::Cyan1), text("  ")),
                    hbox(text("  TOTAL EXPENSES:"), filler(), text(formatCurrency(total_out)) | color(Color::MediumPurple1), text("  ")),
                    text("  ──────────────────────────────────────────  ") | center,
                    hbox(text("  NET BALANCE: "), filler(), text(formatCurrency(total_in - total_out)) | bold | color(Color::White), text("  "))
                }),
                text(""),
            }) | border | color(Color::DeepSkyBlue1),
            text(""),
            back->Render() | center | size(WIDTH, EQUAL, 25)
        }) | borderHeavy | color(Color::DeepSkyBlue1) | center | size(WIDTH, EQUAL, 65);
    });

    screen.Loop(renderer);
}