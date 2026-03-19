#ifndef GLOBALS_H
#define GLOBALS_H

/**
 - @file globals.h
 - @brief Centralized declarations of shared global variables.
          Using 'extern' ensures these variables are accessible 
          across the entire application without duplication.
 */

#include <vector>
#include <string>
#include "../models/classes.h"

/**
 - @var allExpenses: Global vector storing all user expense records.
 */
extern std::vector<Expense> allExpenses; 

/**
 - @var allIncome: Global vector storing all user income records.
 */
extern std::vector<Income> allIncome;    

/**
 - @var currency: Global string for the preferred currency symbol (default set to "$").
 */
extern std::string currency;             

#endif