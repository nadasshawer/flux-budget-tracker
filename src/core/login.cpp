#include "../../include/core/login.h"
#include "../../include/auth/user_info.h" // Add this to access newUser
#include <ftxui/component/component.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>

extern UserInfo newUser; // Reference the same user object

bool loginUser() {
    using namespace ftxui;
    std::string u_name, p_word, error_msg;
    bool success = false;
    auto screen = ScreenInteractive::TerminalOutput();

    Component input_u = Input(&u_name, "Username");
    InputOption pass_opt; pass_opt.password = true;
    Component input_p = Input(&p_word, "••••••••", pass_opt);

    auto btn = Button(" ACCESS SYSTEM ", [&] { 
        // PASSWORD VALIDATION LOGIC
        if (u_name == newUser.getUsername() && p_word == newUser.getPassword()) {
            success = true; 
            screen.Exit(); 
        } else {
            error_msg = "INVALID CREDENTIALS!";
        }
    });

    auto layout = Container::Vertical({ input_u, input_p, btn });
    auto renderer = Renderer(layout, [&] {
        return vbox({
            text(" F L U X   S Y S T E M S ") | bold | center | color(Color::DeepSkyBlue1),
            text(""),
            vbox({
                text(" SECURE GATEWAY ") | bold | center | color(Color::DeepSkyBlue1),
                text(""),
                hbox(text(" USER: "), input_u->Render() | flex) | border,
                hbox(text(" PASS: "), input_p->Render() | flex) | border,
                text(error_msg) | center | color(Color::Red1),
                text(""),
                btn->Render() | center | bgcolor(Color::DeepSkyBlue1) | color(Color::White)
            }) | borderHeavy | color(Color::DeepSkyBlue1) | size(WIDTH, EQUAL, 40)
        }) | center;
    });

    screen.Loop(renderer);
    return success;
}