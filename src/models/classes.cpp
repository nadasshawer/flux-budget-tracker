// File Imports
#include "../include/models/classes.h"
#include "../include/utils/data_display.h"

// Library Imports
#include <iostream>
#include <string>
#include <vector>

// Global Variables
char newExpChoice;
std::string currency;

/* ============================================================
TRANSACTION CLASS (Base for Expense, Income)
============================================================*/
// SETTERS & GETTERS
// Name
void Transaction::setName(std::string name) {
  bool validName = checkNameInput(name);
  if (validName == true) {
    std::string capitalizedName = capitalizeFirstLetter(name);
    this->Name = capitalizedName;
  } else {
    this->Name = "";
  }
}
std::string Transaction::getName() const { return Name; }

// Month (In Numbers)
void Transaction::setMonth(int month) {
  bool checkedMonth = checkNumMonthInput(month);
  if (checkedMonth) {
    this->Month = month;
  } else {
    this->Month = 0;
  }
}
int Transaction::getMonth() const { return Month; }

// Year
void Transaction::setYear(int year) {
  bool checkedYear = checkYearInput(year);
  if (checkedYear) {
    this->Year = year;
  } else {
    this->Year = 0;
  }
}
int Transaction::getYear() const { return Year; }

// Day
void Transaction::setDay(int day) {
  MonthInfo monthDetails = mapMonthInfo(day, this->Month, this->Year);
  bool checkedDay = checkDayInput(day, monthDetails);
  if (checkedDay) {
    this->Day = day;
  } else {
    this->Day = 0;
  }
}
int Transaction::getDay() const { return Day; }

// Category
void Transaction::setCategory(std::string category) {
  bool validCategory = checkNameInput(category);
  if (validCategory == true) {
    std::string capitalizedCategory = capitalizeFirstLetter(category);
    this->Category = capitalizedCategory;
  } else {
    this->Category = "";
  }
}
std::string Transaction::getCategory() const { return Category; }

// Description
void Transaction::setDescription(std::string description) {
  std::string capitalizedDescription = capitalizeFirstLetter(description);
  this->Description = capitalizedDescription;
}
std::string Transaction::getDescription() const { return Description; }

// Amount
void Transaction::setAmount(double amount) {
  double roundedAmount = roundTo2Digits(amount);
  this->Amount = roundedAmount;
}
double Transaction::getAmount() const { return Amount; }

// CONSTRUCTORS
// Default constructor
Transaction::Transaction() {
  Name = "";
  Day = 0;
  Month = 0;
  Year = 0;
  Category = "";
  Description = "";
  Amount = 0;
}

// Stored Transaction Info Constructor
Transaction::Transaction(const std::string cName, const int cDay,
                         const int cMonth, const int cYear,
                         const std::string cCategory,
                         const std::string cDescription, const double cAmount) {
  setName(cName);
  setMonth(cMonth);
  setYear(cYear);
  setDay(cDay);
  setCategory(cCategory);
  setDescription(cDescription);
  setAmount(cAmount);
}

/* ============================================================
EXPENSE CLASS
============================================================*/
// CONSTRUCTORS
// Default constructor
Expense::Expense() {
  Name = "";
  Day = 0;
  Month = 0;
  Year = 0;
  Category = "";
  Description = "";
  Amount = 0;
}

// Stored Expense Info Constructor
Expense::Expense(const std::string cName, const int cDay, const int cMonth,
                 const int cYear, const std::string cCategory,
                 const std::string cDescription, const double cAmount)
    : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                  cAmount) {};

/* ============================================================
INCOME CLASS
============================================================*/
// SETTERS & GETTERS
// Source of Income
void Income::setSource(const std::string source) {
  bool validSource = checkSourceInput(source);
  if (validSource) {
    std::string capitalizedSource = capitalizeFirstLetter(source);
    this->Source = capitalizedSource;
  } else {
    this->Source = "";
  }
}
std::string Income::getSource() const { return Source; }

// Gross Amount
void Income::setGrossAmount(const double grossAmount) {
  this->GrossAmount = grossAmount;
}
double Income::getGrossAmount() const { return GrossAmount; }

// Frequency
void Income::setFrequency(const int frequency) { this->Frequency = frequency; }
int Income::getFrequency() const { return Frequency; }

// Mode
void Income::setMode(const std::string mode) {
  std::string capitalizedMode = capitalizeFirstLetter(mode);
  this->Mode = capitalizedMode;
}
std::string Income::getMode() const { return Mode; }

// Tax Rate
void Income::setTaxRate(const double taxRate) { this->TaxRate = taxRate; }
double Income::getTaxRate() const { return TaxRate; }

// Tax Category
void Income::setTaxCategory(const std::string taxCategory) {
  std::string capitalizedTaxCategory = capitalizeFirstLetter(taxCategory);
  this->TaxCategory = capitalizedTaxCategory;
}
std::string Income::getTaxCategory() const { return TaxCategory; }

// Status
void Income::setStatus(const std::string status) { this->Status = status; }
std::string Income::getStatus() const { return Status; }

// Budget Allocation
void Income::setBudgetAllocation(const std::string budgetAllocation) {
  this->BudgetAllocation = budgetAllocation;
}
std::string Income::getBudgetAllocation() const { return BudgetAllocation; }

// CONSTRUCTORS
// Default Constructor
Income::Income() {
  Name = "";
  Day = 0;
  Month = 0;
  Year = 0;
  Category = "";
  Description = "";
  Source = "";
  GrossAmount = 0;
  Frequency = 0;
  Mode = "";
  TaxRate = 0;
  TaxCategory = "";
  Status = "";
  BudgetAllocation = "";
}

// Stored Income Info Constructor
Income::Income(const std::string cName, const int cDay, const int cMonth,
               const int cYear, const std::string cSource,
               const double cGrossAmount, const std::string cCategory,
               const std::string cDescription, const double cAmount,
               const int cFrequency, const std::string cMode,
               const double cTaxRate, const std::string cTaxCategory,
               const std::string cStatus, const std::string cBudgetAllocation)
    : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                  cAmount) {
  setSource(cSource);
  setGrossAmount(cGrossAmount);
  setFrequency(cFrequency);
  setMode(cMode);
  setTaxRate(cTaxRate);
  setTaxCategory(cTaxCategory);
  setStatus(cStatus);
  setBudgetAllocation(cBudgetAllocation);
};

/* ============================================================
BUDGET CLASS
============================================================*/
// SETTERS & GETTERS
void Budget::setBudgetedAmount(const double budgetedAmount) {
  BudgetedAmount = budgetedAmount;
}
double Budget::getBudgetedAmount() const { return BudgetedAmount; }
void Budget::setActualAmount(const double actualAmount) {
  ActualAmount = actualAmount;
}
double Budget::getActualAmount() const { return ActualAmount; }
/*void Budget::setShortTermGoal(const std::string shortTermGoal) {
        ShortTermGoal = shortTermGoal;
}
std::string Budget::getShortTermGoal() const {
        return ShortTermGoal;
}
void Budget::setLongTermGoal(const std::string longTermGoal) {
        LongTermGoal = longTermGoal;
}
std::string Budget::getLongTermGoal() const {
        return LongTermGoal;
}*/

// CONSTRUCTORS
// default constructor
Budget::Budget() {
  BudgetedAmount = 0;
  ActualAmount = 0;
  /*ShortTermGoal = "";
  LongTermGoal = "";*/
}

// budget info constructor
Budget::Budget(const double cBudgetedAmount, const double cActualAmount,
               const std::string cShortTermGoal,
               const std::string cLongTermGoal) {
  BudgetedAmount = cBudgetedAmount;
  ActualAmount = cActualAmount;
  /*ShortTermGoal = cShortTermGoal;
  LongTermGoal = cLongTermGoal;*/
}

// METHODS
void Budget::calcDifference() {
  double difference;
  difference = BudgetedAmount - ActualAmount;
  if (difference < 0) {
    std::cout << difference << " (You have a negative cash flow)" << endl;
  } else {
    std::cout << difference << " (You have a positive cash flow)" << endl;
  }
}

// DISPLAY BUDGET DATA
void Budget::displayBudgetData() {
  std::cout << "v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^v^" << endl;
  std::cout << "<[ BUDGET SUMMARY ]>" << endl << endl;
  std::cout << "- Budgeted Amount: " << currency << getBudgetedAmount() << endl;
  std::cout << "- Actual Amount: " << currency << getActualAmount() << endl;
  std::cout << "- Difference: " << currency << " ";
  calcDifference();
}
