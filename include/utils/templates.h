#ifndef TEMPLATES_H
#define TEMPLATES_H

/**
 - @file templates.h
 - @brief Advanced generic utilities for data filtering and reporting.
         This file contains template-based functions that use member function 
         pointers to dynamically access class data for filtering and display.
 */

// File Imports
#include "../models/classes.h"

// Library Imports
#include <string>
#include <iostream>
#include <vector>

/**
 - @brief Filters and prints expense names based on a specific attribute.
 - @tparam T: The data type of the attribute being filtered (e.g., char, int).
 - @param getter: A member function pointer to an Expense getter method.
 - @param classification: The target value to match against the getter's return.
 - @note This function iterates through the global allExpenses vector.
 */
template <typename T>   // template to allow the function to accept diff getter types
void printExpNames(T (Expense::*getter)() const, T classification) {
  bool foundExpense = false;
  std::string expNames;
  int expInCategoryCount = 0;
  for (const auto &expense : allExpenses) {
    if ((expense.*getter)() ==
        classification) { // member function pointer to getter method
      if (expInCategoryCount > 0) {
        expNames += ", ";
      }
      expNames += expense.getName();
      expInCategoryCount++;
      foundExpense = true;
    }
  }
  if (foundExpense) {
    std::cout << endl
              << "- Expenses belonging to " << classification << " ("
              << expInCategoryCount << "): " << expNames << endl;
  } else {
    std::cout << "Oops! No expenses found in this category." << endl;
    foundExpense = false;
  }
}

/**
 - @brief Filters and prints income sources based on a specific attribute.
 - @tparam T: The data type of the attribute being filtered.
 - @param getter: A member function pointer to an Income getter method.
 - @param classification: The target value to match against the getter's return.
 - @note This function iterates through the global allIncome vector.
 */
template <typename T>
void printIncNames(T (Income::*getter)() const, T classification) {
  bool foundIncome = false;
  std::string incNames;
  double incAmounts;
  int incInCategoryCount = 0;
  for (const auto &income : allIncome) {
    if ((income.*getter)() == classification) {
      if (incInCategoryCount > 0) {
        incNames += ", ";
      }
      incNames += income.getBusiness();
      incAmounts = income.getGrossAmount();
      incInCategoryCount++;
      foundIncome = true;
    }
  }
  if (foundIncome) {
    std::cout << endl
              << "- Income belonging to " << classification << " ("
              << incInCategoryCount << ") from: " << " " << incNames << " of "
              << currency << incAmounts << endl;
  } else {
    std::cout << "Oops! No income found in this category." << endl;
    foundIncome = false;
  }
}

/**
 - @brief Automatically sets the current system date or allows manual entry for an object.
 - @tparam R: The class type (e.g., Expense or Income).
 - @param object: The specific instance being modified.
 - @param setterDay: Pointer to the object's setDay method.
 - @param setterMonth: Pointer to the object's setMonth method.
 - @param setterYear: Pointer to the object's setYear method.
 - @return bool: Returns true if system date was used, false if manually entered.
 */
template <typename R>
bool chooseTodayAsDate(R &object, void (R::*setterDay)(int),
                       void (R::*setterMonth)(int),
                       void (R::*setterYear)(int)) {
  char useTodayDateOption;
  int day;
  int month;
  int year;
  while (true) {
    std::cin >> useTodayDateOption;
    std::cin.clear();
    std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (std::cin.good()) {
      if (useTodayDateOption == 'Y' || useTodayDateOption == 'y') {
        int currentDay = getCurrentDay();
        int currentMonth = getCurrentMonth();
        int currentYear = getCurrentYear();
        (object.*setterDay)(currentDay);
        (object.*setterMonth)(currentMonth);
        (object.*setterYear)(currentYear);
        return true;
      } else if (useTodayDateOption == 'N' || useTodayDateOption == 'n') {
        std::cout << "- Day: ";
        while (true) {
          std::cin >> day;
          if (std::cin.good() && checkDayInput(day)) {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            (object.*setterDay)(day);
            break;
          } else {
            std::cout << "Please enter a valid day! Retry --> ";
            std::cin.clear();
            std::cin.ignore();
          }
        }
        // month
        std::cout << "- Month (in digits): ";
        while (true) {
          std::cin >> month;
          if (std::cin.good() && checkNumMonthInput(month)) {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            (object.*setterMonth)(month);
            break;
          } else {
            std::cout << "Please enter a valid month! Retry --> ";
            std::cin.clear();
            std::cin.ignore();
          }
        }
        // year
        std::cout << "- Year: ";
        while (true) {
          std::cin >> year;
          if (std::cin.good() && checkYearInput(year)) {
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            (object.*setterYear)(year);
            break;
          } else {
            std::cout << "Please enter a reasonable year! Retry --> ";
            std::cin.clear();
            std::cin.ignore();
          }
        }
        return false;
      } else {
        std::cout << "Please enter a valid Y/N option! Retry --> ";
      }
    }
  }
}

#endif