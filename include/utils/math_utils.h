#ifndef MATH_UTILS_H
#define MATH_UTILS_H

/**
 - @file math.h
 - @brief Mathematical utility functions for financial calculations and rounding.
          This file provides helper functions for numeric processing, 
          rounding for currency, and digit analysis.
 */

/**
 - @brief Calculates the number of digits in an integer.
 - @param num: The integer to be analyzed.
 - @return int: The total number of digits.
 */
int digitCount(int num);

/**
 - @brief Rounds a decimal value to exactly two decimal places.
 - @param num: The raw double value to round.
 - @return double: The value rounded to 2 decimal places.
 */
double roundTo2Digits(double num);

/**
 - @brief Calculates the sum of all recorded expense amounts.
 - @details Iterates through the global or passed vector of expense values 
            to provide a grand total. 
 - @return double: The total sum of all expenses.
 */
double calcExpenseTotal();

/**
 - @brief Calculates the total net income after tax deductions and frequency adjustments.
 - @details This function applies the tax rate to the gross amount and 
            multiplies by the payment frequency to determine the actual 
            take-home pay.
 - @return double: The total net income for the specified period.
 */
double calcIncomeTotal();

#endif