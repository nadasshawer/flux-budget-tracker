#ifndef CLASSES_H
#define CLASSES_H

// Library Imports
#include <string>
#include <vector>

/**
 - @struct MonthInfo
 - @brief A container for month-specific data.
 - @var name: The string name of the month (e.g., "January").
 - @var monthNum: The integer representation (1-12).
 - @var maxDays: The total days in that month, accounting for leap years.
 */
struct MonthInfo {
    std::string name;
    int monthNum;
    int maxDays;
};

/* ============================================================
TRANSACTION CLASS (Parent for Expense, Income)
============================================================*/
class Transaction {
protected:
  // Attributes
  std::string Name;
  int Day;
  int Month;
  int Year;
  std::string Category;
  std::string Description;
  double Amount;

public:
  // Setters
  void setName(const std::string name);
  void setDay(const int day);
  void setMonth(const int month);
  void setYear(const int year);
  void setCategory(const std::string category);
  void setDescription(const std::string description);
  void setAmount(const double amount);

  // Getters
  std::string getName() const;
  int getDay() const;
  int getMonth() const;
  int getYear() const;
  std::string getCategory() const;
  std::string getDescription() const;
  double getAmount() const;

  // Constructors
  Transaction();
  Transaction(const std::string cName, const int cDay, const int cMonth,
              const int cYear, const std::string cCategory,
              const std::string cDescription, const double cAmount);
};

/* ============================================================
EXPENSE CLASS
============================================================*/
class Expense : public Transaction {
public:
  // Constructors
  Expense() : Transaction() {};
  Expense(const std::string cName, const int cDay, const int cMonth,
          const int cYear, const std::string cCategory,
          const std::string cDescription, const double cAmount)
      : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                    cAmount) {};
};

/* ============================================================
INCOME CLASS
============================================================*/
class Income : public Transaction {
private:
  // Attributes
  std::string Source;
  double GrossAmount;
  int Frequency;
  std::string Mode;
  double TaxRate;
  std::string TaxCategory;
  std::string Status;
  std::string BudgetAllocation;

public:
  // Setters
  void setSource(const std::string source);
  void setGrossAmount(const double grossAmount);
  void setFrequency(const int frequency);
  void setMode(const std::string mode);
  void setTaxRate(const double taxRate);
  void setTaxCategory(const std::string taxCategory);
  void setStatus(const std::string status);
  void setBudgetAllocation(const std::string budgetAllocation);

  // Getters
  std::string getSource() const;
  double getGrossAmount() const;
  int getFrequency() const;
  std::string getMode() const;
  double getTaxRate() const;
  std::string getTaxCategory() const;
  std::string getStatus() const;
  std::string getBudgetAllocation() const;

  // Constructors
  Income() : Transaction() {};
  Income(const std::string cName, const int cDay, const int cMonth,
         const int cYear, const std::string cSource, const double cGrossAmount,
         const std::string cCategory, const std::string cDescription,
         const double cAmount, const int cFrequency, const std::string cMode,
         const double cTaxRate, const std::string cTaxCategory,
         const std::string cStatus, const std::string cBudgetAllocation)
      : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                    cAmount) {};
};

/* ============================================================
BUDGET CLASS
============================================================*/
class Budget {
protected:
  // VARIABLES
  double BudgetedAmount;
  double ActualAmount;
  /*std::string ShortTermGoal;
  std::string LongTermGoal;*/

public:
  // SETTERS
  void setBudgetedAmount(const double budgetedAmount);
  void setActualAmount(const double actualAmount);
  /*void setShortTermGoal(const std::string shortTermGoal);
  void setLongTermGoal(const std::string longTermGoal);*/

  // GETTERS
  double getBudgetedAmount() const;
  double getActualAmount() const;
  /*std::string getShortTermGoal() const;
  std::string getLongTermGoal() const;*/

  // CONSTRUCTORS
  Budget();
  Budget(const double cBudgetedAmount, const double cActualAmount,
         const std::string cShortTermGoal, const std::string cLongTermGoal);

  // METHODS
  void calcDifference();
  void displayBudgetData();
};

#endif