// File Imports
#include "../../include/models/budget.h"

// --- Budget Class ---
// Setters & Getters
bool Budget::setBudgetedAmount(double budgetedAmount) {
  BudgetedAmount = budgetedAmount;
  return true;
}
double Budget::getBudgetedAmount() const { return BudgetedAmount; }
bool Budget::setActualAmount(double actualAmount) {
  ActualAmount = actualAmount;
  return true;
}
double Budget::getActualAmount() const { return ActualAmount; }

// Default Constructor
Budget::Budget() {
  BudgetedAmount = 0;
  ActualAmount = 0;
}

// Stored Budget Info Constructor
Budget::Budget(double cBudgetedAmount, double cActualAmount) {
  BudgetedAmount = cBudgetedAmount;
  ActualAmount = cActualAmount;
}

// Methods
std::string Budget::calcDifference() {
  double difference;
  difference = BudgetedAmount - ActualAmount;
  if (difference < 0) {
    return "-ve cash flow";
  } else {
    return "+ve cash flow";
  }
}
