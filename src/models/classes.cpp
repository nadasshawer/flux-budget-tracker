// File Imports
#include "../../include/models/classes.h"
#include "../../include/validation/validation.h"
#include "../../include/utils/text_utils.h"
#include "../../include/utils/math_utils.h"
#include "../../include/core/globals.h"

// Library Imports
#include <string>
#include <vector>


// --- Transactions Class (Base for Expense, Income) ---
// Setters & Getters
bool Transaction::setName(const std::string& name) {
  bool validName = checkNameInput(name);
  if (validName == true) {
    std::string capitalizedName = capitalizeFirstLetter(name);
    this->Name = capitalizedName;
    return true;
  } else {
    return false;
  }
}
std::string Transaction::getName() const { return Name; }

bool Transaction::setMonth(int month) {
  bool checkedMonth = checkNumMonthInput(month);
  if (checkedMonth) {
    this->Month = month;
    return true;
  } else {
    return false;
  }
}
int Transaction::getMonth() const { return Month; }

bool Transaction::setYear(int year) {
  bool checkedYear = checkYearInput(year);
  if (checkedYear) {
    this->Year = year;
    return true;
  } else {
    return false;
  }
}
int Transaction::getYear() const { return Year; }

bool Transaction::setDay(int day) {
  MonthInfo monthDetails = mapMonthInfo(this->Month, this->Year);
  bool checkedDay = checkDayInput(day, monthDetails);
  if (checkedDay) {
    this->Day = day;
    return true;
  } else {
    return false;
  }
}
int Transaction::getDay() const { return Day; }

bool Transaction::setCategory(const std::string& category) {
  bool validCategory = checkNameInput(category);
  if (validCategory == true) {
    std::string capitalizedCategory = capitalizeFirstLetter(category);
    this->Category = capitalizedCategory;
    return true;
  } else {
    return false;
  }
}
std::string Transaction::getCategory() const { return Category; }

bool Transaction::setDescription(const std::string& description) {
  std::string capitalizedDescription = capitalizeFirstLetter(description);
  this->Description = capitalizedDescription;
  return true;
}
std::string Transaction::getDescription() const { return Description; }

bool Transaction::setAmount(double amount) {
  double roundedAmount = roundTo2Digits(amount);
  this->Amount = roundedAmount;
  return true;
}
double Transaction::getAmount() const { return Amount; }

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
Transaction::Transaction(const std::string& cName, const int cDay,
                         const int cMonth, const int cYear,
                         const std::string& cCategory,
                         const std::string& cDescription, const double cAmount) {
  setName(cName);
  setMonth(cMonth);
  setYear(cYear);
  setDay(cDay);
  setCategory(cCategory);
  setDescription(cDescription);
  setAmount(cAmount);
}

// --- Expenses Class ---
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
Expense::Expense(const std::string& cName, int cDay, int cMonth,
                 int cYear, const std::string& cCategory,
                 const std::string& cDescription, double cAmount)
    : Transaction(cName, cDay, cMonth, cYear, cCategory, cDescription,
                  cAmount) {};

// --- Income Class ---
// Setters & Getters
bool Income::setSource(const std::string& source) {
  bool validSource = checkSourceInput(source);
  if (validSource) {
    std::string capitalizedSource = capitalizeFirstLetter(source);
    this->Source = capitalizedSource;
    return true;
  } else {
    return false;
  }
}
std::string Income::getSource() const { return Source; }

bool Income::setGrossAmount(double grossAmount) {
  this->GrossAmount = grossAmount;
  return true;
}
double Income::getGrossAmount() const { return GrossAmount; }

bool Income::setFrequency(int frequency) { 
  this->Frequency = frequency; 
  return true;
}
int Income::getFrequency() const { return Frequency; }

bool Income::setMode(const std::string& mode) {
  std::string capitalizedMode = capitalizeFirstLetter(mode);
  this->Mode = capitalizedMode;
  return true;
}
std::string Income::getMode() const { return Mode; }

bool Income::setTaxRate(double taxRate) { 
  this->TaxRate = taxRate; 
  return true;
}
double Income::getTaxRate() const { return TaxRate; }

bool Income::setTaxCategory(const std::string& taxCategory) {
  std::string capitalizedTaxCategory = capitalizeFirstLetter(taxCategory);
  this->TaxCategory = capitalizedTaxCategory;
  return true;
}
std::string Income::getTaxCategory() const { return TaxCategory; }

bool Income::setStatus(const std::string& status) { 
  this->Status = status; 
  return true;
}
std::string Income::getStatus() const { return Status; }

bool Income::setBudgetAllocation(const std::string& budgetAllocation) {
  this->BudgetAllocation = budgetAllocation;
  return true;
}
std::string Income::getBudgetAllocation() const { return BudgetAllocation; }

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
Income::Income(const std::string& cName, int cDay, int cMonth,
               int cYear, const std::string& cSource,
               double cGrossAmount, const std::string& cCategory,
               const std::string& cDescription, double cAmount,
               int cFrequency, const std::string& cMode,
               double cTaxRate, const std::string& cTaxCategory,
               const std::string& cStatus, const std::string& cBudgetAllocation)
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