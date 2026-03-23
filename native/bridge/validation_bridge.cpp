// Imports
#include "../../include/validation/validation.h"
#include <string>

// Wrapper
// Translates our C++ code into C so JS can understand it
extern "C" {
    // --- checkNameInput ---
    bool bridgeCheckName(const char* name_from_ui) {
        std::string name_str(name_from_ui);
        return checkNameInput(name_str);
    }

    // --- checkDayInput ---
    bool bridgeCheckDay(int day, int month, int year){
        MonthInfo monthInfo = mapMonthInfo(month, year);
        return checkDayInput(day, monthInfo);
    }
    
    // --- checkNumMonthInput ---
    bool bridgeCheckNumMonth(int month){
        return checkNumMonthInput(month);
    }

    // --- checkYearInput ---
    bool bridgeCheckYear(int year) {
        return checkYearInput(year);
    }

    // --- checkSourceInput ---
    bool bridgeCheckSource(const char* source_from_ui){
        std::string source_str(source_from_ui);
        return checkSourceInput(source_str);
    }

    // --- checkGrossAmount ---
    bool bridgeCheckGrossAmount(double amount){
        return checkGrossAmount(amount);
    }
}