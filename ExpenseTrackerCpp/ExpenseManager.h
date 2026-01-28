#ifndef EXPENSE_MANAGER_H
#define EXPENSE_MANAGER_H

#include <vector>
#include "Expense.h"

class ExpenseManager {
private:
    std::vector<Expense> expenses;
    int nextId = 1;

public:
    void loadFromFile();
    void saveToFile();
    void addExpense();
    void viewExpenses();
    void deleteExpense();
    void filterByCategory();
    void monthlySummary();
    void budgetWarning();
    void exportToCSV();
};

#endif