#ifndef FUNCTIONAL_UTILS_H
#define FUNCTIONAL_UTILS_H

/**
 - @file functional_utils.h
 - @brief Utilities for higher-order functions and callback management.
          Provides type definitions and logic for passing functions as 
          arguments to manage UI flow and logic branching.
 */

#include <functional>

/** 
 - @brief A versatile function wrapper that takes no arguments and returns void.
          Used for passing logic like 'getExpenseInfo' or lambda expressions.
 */
typedef std::function<void()> FunctionA;

/** 
 - @brief A C-style function pointer for functions returning a double.
          Typically used for mathematical callbacks or data retrieval.
 */
typedef double (*FunctionB)();

/**
 - @brief Handles a Universal Yes/No choice logic in the terminal.
 - @param functionA: The logic to execute if the user chooses 'Yes'.
 - @param functionB: The logic to execute if the user chooses 'No' (optional).
 - @return bool: Returns true for 'Yes', false for 'No'.
 */
bool newChoice(FunctionA functionA, FunctionB functionB = nullptr);

#endif
