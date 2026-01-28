#include "ExpenseManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

void ExpenseManager::addExpense() {
    Expense e;
    e.id = nextId++;

    std::cout << "Amount: ";
    std::cin >> e.amount;

    std::cin.ignore();
    std::cout << "Category: ";
    getline(std::cin, e.category);

    std::cout << "Date (YYYY-MM-DD): ";
    getline(std::cin, e.date);

    std::cout << "Note: ";
    getline(std::cin, e.note);

    expenses.push_back(e);
    std::cout << "Expense added!\n";
}

void ExpenseManager::deleteExpense()
{
    int id;
    std::cout << "Enter Expense ID to delete: ";
    std::cin >> id;

    for (auto it = expenses.begin(); it != expenses.end(); ++it)
    {
        if (it->id == id)
        {
            expenses.erase(it);
            std::cout << "Expense deleted.\n";
            return;
        }
    }
    std::cout << "Expense not found.\n";
}
void ExpenseManager::filterByCategory() {
    std::string category;
    std::cin.ignore();

    std::cout << "Enter category: ";
    getline(std::cin, category);

    bool found = false;
    for (const auto& e : expenses) {
        if (e.category == category) {
            std::cout << e.id << " | "
                      << e.amount << " | "
                      << e.date << " | "
                      << e.note << "\n";
            found = true;
        }
    }

    if (!found) {
        std::cout << "No expenses found for this category.\n";
    }
}

void ExpenseManager::monthlySummary() {
    std::string month;
    double total = 0.0;

    std::cin.ignore();
    std::cout << "Enter month (YYYY-MM): ";
    getline(std::cin, month);

    for (const auto& e : expenses) {
        if (e.date.substr(0, 7) == month) {
            total += e.amount;
        }
    }

    std::cout << "Total spent in " << month << ": " << total << "\n";
}

void ExpenseManager::budgetWarning() {
    std::string month;
    double budget;
    double total = 0.0;

    std::cin.ignore();
    std::cout << "Enter month (YYYY-MM): ";
    getline(std::cin, month);

    std::cout << "Enter budget amount: ";
    std::cin >> budget;

    for (const auto& e : expenses) {
        if (e.date.substr(0, 7) == month) {
            total += e.amount;
        }
    }

    std::cout << "\nSpent: " << total << "\n";
    std::cout << "Budget: " << budget << "\n";

    if (total > budget) {
        std::cout << "Alert!! -> Budget exceeded!\n";
    } else {
        std::cout << "Within budget.\n";
    }
}

void ExpenseManager::exportToCSV() {
    std::ofstream file("expenses_export.csv");

    if (!file.is_open()) {
        std::cout << "Failed to create export file.\n";
        return;
    }

    file << "ID,Amount,Category,Date,Note\n";

    for (const auto& e : expenses) {
        file << e.id << "|"
             << e.amount << "|"
             << e.category << "|"
             << e.date << "|"
             << e.note << "\n";
    }

    file.close();
    std::cout << "Expenses exported to expenses_export.csv\n";
}

void ExpenseManager::viewExpenses() {
    for (const auto& e : expenses) {
        std::cout << e.id << " | "
                  << e.amount << " | "
                  << e.category << " | "
                  << e.date << " | "
                  << e.note << "\n";
    }
}

void ExpenseManager::saveToFile() {
    std::ofstream file("data.csv");
    for (const auto& e : expenses) {
        file << e.id << ","
             << e.amount << ","
             << e.category << ","
             << e.date << ","
             << e.note << "\n";
    }
    file.close();
}

void ExpenseManager::loadFromFile() {
    std::ifstream file("data.csv");
    if (!file.is_open()) return;

    std::string line;
    while (getline(file, line)) {
        Expense e;
        std::stringstream ss(line);
        std::string temp;

        getline(ss, temp, ','); e.id = stoi(temp);
        getline(ss, temp, ','); e.amount = stod(temp);
        getline(ss, e.category, ',');
        getline(ss, e.date, ',');
        getline(ss, e.note);

        expenses.push_back(e);
        nextId = e.id + 1;
    }
    file.close();
}