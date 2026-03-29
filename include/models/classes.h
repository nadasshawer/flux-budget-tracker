/**
 - @file classes.h
 - @brief Defines the core financial data structures for the ledger system.
 - @details Contains the inheritance hierarchy for Transactions (Expenses and Income) 
            and the Budget tracking classes. This file serves as the primary data 
            model for the whole system.
 */

#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <vector>

/**
 - @struct MonthInfo
 - @brief A utility container for month-specific calendar data.
 - @details Used for date validation to ensure entered days do not exceed 
            the specific month's maximum, accounting for leap years.
 */
struct MonthInfo {
    std::string name;
    int monthNum;
    int maxDays;
};

/**
 - @class Transaction
 - @brief The base class for all financial movements.
 - @details Provides core attributes and validation logic for names, dates, 
            and amounts. Both Expense and Income inherit from this class.
 */
class Transaction {
protected:
    std::string Name;
    int Day;
    int Month;
    int Year;
    std::string Category;
    std::string Description;
    double Amount;

public:
    // --- Setters ---
    /**
     - @brief Sets and validates the transaction name.
     - @details Ensures the name is not empty and applies standard capitalization.
     - @param name: The raw string input from the user or UI.
     */
    bool setName(const std::string& name);

    /**
     - @brief Validates and sets the day of the transaction.
     - @details Requires Month and Year to be set first to calculate max days allowed.
     - @param day: Integer representing the day of the month (1-31).
     */
    bool setDay(int day);

    /**
     - @brief Sets the month of the transaction.
     - @details Validates that the input falls between 1 and 12.
     - @param month: Integer representing the month.
     */
    bool setMonth(int month);

    /**
     - @brief Sets the year of the transaction.
     - @details Checks if the year is within a reasonable financial range.
     - @param year: Integer representing the year (YYYY).
     */
    bool setYear(int year);

    /**
     - @brief Sets the transaction category.
     - @details Groups the transaction for budget tracking (e.g., Food, Rent).
     - @param category: String representing the type of spending/earning.
     */
    bool setCategory(const std::string& category);

    /**
     - @brief Sets the transaction description.
     - @details Capitalizes the first letter for consistent display in the UI.
     - @param description: Additional details or notes about the transaction.
     */
    bool setDescription(const std::string& description);

    /**
     - @brief Sets the transaction amount.
     - @details Rounds the input to two decimal places using math_utils logic.
     - @param amount: The monetary value of the transaction.
     */
    bool setAmount(double amount);

    // --- Getters ---
    /**
     - @brief Retrieves the transaction name.
     - @return std::string: The stored name attribute.
     */
    std::string getName() const;

    /**
     - @brief Retrieves the transaction day.
     - @return int: The stored day of the month.
     */
    int getDay() const;

    /**
     - @brief Retrieves the transaction month.
     - @return int: The stored month (1-12).
     */
    int getMonth() const;

    /**
     - @brief Retrieves the transaction year.
     - @return int: The stored year (YYYY).
     */
    int getYear() const;

    /**
     - @brief Retrieves the transaction category.
     - @return std::string: The stored category name.
     */
    std::string getCategory() const;

    /**
     - @brief Retrieves the transaction description.
     - @return std::string: The stored description text.
     */
    std::string getDescription() const;

    /**
     - @brief Retrieves the transaction amount.
     - @return double: The stored monetary value.
     */
    double getAmount() const;

    // --- Constructors ---
    /**
     - @brief Default constructor for Transaction.
     - @details Initializes all strings to empty and numerical values to zero.
     */
    Transaction();

    /**
     - @brief Parameterized constructor for a full transaction.
     - @details Automatically runs all inputs through setter validation methods.
     - @param cName, cDay, cMonth, cYear, cCategory, cDescription, cAmount: Core data points.
     */
    Transaction(const std::string& cName, int cDay, int cMonth,
                int cYear, const std::string& cCategory,
                const std::string& cDescription, double cAmount);
};

/**
 - @class Expense
 - @brief Specialized class for outgoing financial transactions.
 - @details Inherits from Transaction. Primarily used to categorize debits.
 */
class Expense : public Transaction {
public:
    /**
     - @brief Default constructor for Expense.
     - @details Inherits initial state from the Transaction base class.
     */
    Expense() : Transaction() {};

    /**
     - @brief Parameterized constructor for an expense.
     - @details Passes all parameters to the base Transaction constructor for validation.
     */
    Expense(const std::string& cName, int cDay, int cMonth,
            int cYear, const std::string& cCategory,
            const std::string& cDescription, double cAmount)
        : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                      cAmount) {};
};

/**
 - @class Income
 - @brief Specialized class for incoming financial transactions.
 - @details Extends Transaction with attributes for tax, frequency, and allocation.
 */
class Income : public Transaction {
private:
    std::string Source;
    double GrossAmount;
    int Frequency;
    std::string Mode;
    double TaxRate;
    std::string TaxCategory;
    std::string Status;
    std::string BudgetAllocation;

public:
    // --- Setters ---
    /**
     - @brief Sets and validates the income source.
     - @details Capitalizes the source name (e.g., "Work" or "Freelance").
     - @param source: String representing the origin of funds.
     */
    bool setSource(const std::string& source);

    /**
     - @brief Sets the pre-tax income amount.
     - @param grossAmount: Double representing total earned before deductions.
     */
    bool setGrossAmount(double grossAmount);

    /**
     - @brief Sets the frequency of the income payment.
     - @details Integer mapped to specific intervals (e.g., 1 for Monthly).
     - @param frequency: Integer code for payment timing.
     */
    bool setFrequency(int frequency);

    /**
     - @brief Sets the payment method/mode.
     - @param mode: String describing how funds are received (e.g., "E-transfer").
     */
    bool setMode(const std::string& mode);

    /**
     - @brief Sets the percentage of tax to be applied.
     - @param taxRate: Double representing the tax percentage (e.g., 0.15).
     */
    bool setTaxRate(double taxRate);

    /**
     - @brief Sets the legal or internal tax category.
     - @param taxCategory: String classification for tax reporting.
     */
    bool setTaxCategory(const std::string& taxCategory);

    /**
     - @brief Sets the current clearance status.
     - @param status: String (e.g., "Pending", "Cleared").
     */
    bool setStatus(const std::string& status);

    /**
     - @brief Assigns income to a specific budget module.
     - @param budgetAllocation: String identifying the target budget.
     */
    bool setBudgetAllocation(const std::string& budgetAllocation);

    // --- Getters ---
    /** 
     - @brief Retrieves the income source. 
     - @return std::string. 
     */
    std::string getSource() const;

    /** 
     - @brief Retrieves the gross amount. 
     - @return double. 
     */
    double getGrossAmount() const;

    /** 
     - @brief Retrieves frequency code. 
     - @return int. 
     */
    int getFrequency() const;

    /** 
     - @brief Retrieves payment mode. 
     - @return std::string. 
     */
    std::string getMode() const;

    /** 
     - @brief Retrieves tax rate. 
     - @return double. 
     */
    double getTaxRate() const;

    /** 
     - @brief Retrieves tax category. 
     - @return std::string. 
     */
    std::string getTaxCategory() const;

    /** 
     - @brief Retrieves payment status. 
     - @return std::string. 
     */
    std::string getStatus() const;

    /** 
     - @brief Retrieves the budget target. 
     - @return std::string. 
     */
    std::string getBudgetAllocation() const;

    // --- Constructors ---
    /**
     - @brief Default constructor for Income.
     */
    Income() : Transaction() {};

    /**
     - @brief Parameterized constructor for a full income record.
     - @details Initializes base transaction data and unique income attributes.
     */
    Income(const std::string& cName, int cDay, int cMonth,
           int cYear, const std::string& cSource, double cGrossAmount,
           const std::string& cCategory, const std::string& cDescription,
           double cAmount, int cFrequency, const std::string& cMode,
           double cTaxRate, const std::string& cTaxCategory,
           const std::string& cStatus, const std::string& cBudgetAllocation);
};

#endif