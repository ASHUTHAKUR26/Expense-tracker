#ifndef EXPENSE_H
#define EXPENSE_H

#include <string>

struct Expense {
    int id;
    double amount;
    std::string category;
    std::string date;   // YYYY-MM-DD
    std::string note;
};

#endif