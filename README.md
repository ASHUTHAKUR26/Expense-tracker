# Expense-tracker
A console-based Expense Tracker application built in C++ to efficiently manage daily expenses with features like categorization, sorting, budgeting, and CSV export.

This project focuses on core C++ concepts, clean logic design, and file handling — with no GUI dependencies.

## 📌 Features

- ➕ Add new expenses (amount, category, date, note)
- 📄 View all expenses
- ❌ Delete expenses by ID
- 🔍 Filter expenses by category
- 📅 Monthly expense summary
- ⚠️ Budget limit warning (monthly)
- 🔃 Sort expenses by:
  - Amount
  - Date
- 💾 Save & load expenses from file
- 📤 Export expenses to CSV (Excel / Google Sheets compatible)

  ## 🛠️ Technologies Used

- **Language:** C++
- **Concepts:**
  - Object-Oriented Programming (OOP)
  - STL (`vector`, `algorithm`)
  - File Handling (`fstream`)
  - Lambda Functions
- **Data Storage:** CSV File
- **Interface:** Console (Terminal)

## 📂 Project Structure

ExpenseTracker/ │── main.cpp │── Expense.h │── ExpenseManager.h │── ExpenseManager.cpp │── data.csv

## 🧾 Sample Menu

- Add Expense
- View Expenses
- Delete Expense
- Filter by Category
- Monthly Summary
- Budget Warning 
- Sort by Amount
- Sort by Date
- Export to CSV
- Save & Exit

## 📁 CSV Export Format

The application allows users to export all expense data into a **CSV file**, which can be easily opened and analyzed using **Microsoft Excel**, **Google Sheets**, or any spreadsheet software.

### CSV Columns
- **ID** – Unique expense identifier  
- **Amount** – Expense amount  
- **Category** – Expense category (Food, Rent, Travel, etc.)  
- **Date** – Date of expense (YYYY-MM-DD)  
- **Note** – Optional description  

## 🙌 Author

Developed by **Ashu Kr Thakur**
