#include <iostream>
#include "ExpenseManager.h"

int main() {
    ExpenseManager manager;
    manager.loadFromFile();

    int choice;
    do {
        std::cout << "\n1. Add Expense\n";
        std::cout << "2. Delete Expense\n";
        std::cout << "3. View Expenses\n";
        std::cout << "4. Filter by Category\n";
        std::cout << "5. Monthly Summary\n";
        std::cout << "6. Budget Warning\n";
        std::cout << "7. Export to CSV\n";
        std::cout << "8. Save & Exit\n";
       
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                manager.addExpense();
                break;
            case  2:
                manager.deleteExpense();
                break;
            case 3:
                manager.viewExpenses();
                break;
            case 4:
                manager.filterByCategory();
                break;
            case 5:
                manager.monthlySummary();
                break;
            case 6:
                manager.budgetWarning();
                break;
            case 7:
            manager.exportToCSV();
            break;
            case 8:
                manager.saveToFile();
                std::cout << "Saved. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 8);

    return 0;
}