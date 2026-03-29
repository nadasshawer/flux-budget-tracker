/**
 - @file budget.h
 - @brief Defines the ...
 - @details Contains the ...
 */

#ifndef BUDGET_H
#define BUDGET_H

#include <string>

/**
 - @class Budget
 - @brief Management class for tracking spending vs. limits.
 - @details Analyzes financial health by comparing budgeted goals to actual data.
 */
class Budget {
protected:
    double BudgetedAmount;
    double ActualAmount;

public:
    // --- Setters ---
    /**
     - @brief Sets the maximum spending limit for this budget.
     - @param budgetedAmount: Double representing the goal limit.
     */
    bool setBudgetedAmount(double budgetedAmount);

    /**
     - @brief Sets the real-world spending amount recorded.
     - @param actualAmount: Double representing the current total spend.
     */
    bool setActualAmount(double actualAmount);

    // --- Getters ---
    /** 
     - @brief Returns the budget limit.
     - @return double. 
     */
    double getBudgetedAmount() const;

    /** 
     - @brief Returns actual spending.
     - @return double. 
     */
    double getActualAmount() const;

    // --- Constructors ---
    /**
     - @brief Default constructor for Budget.
     */
    Budget();

    /**
     - @brief Parameterized constructor for budget tracking.
     - @param cBudgetedAmount, cActualAmount: Initial goal and spending values.
     */
    Budget(double cBudgetedAmount, double cActualAmount);

    // --- Methods ---
    /**
     - @brief Calculates the health of the current cash flow.
     - @details Subtracts actual spending from the budget to find the delta.
     - @return std::string: Returns "+ve cash flow" if under budget, "-ve" if over.
     */
    std::string calcDifference();
};

#endif