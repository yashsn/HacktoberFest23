import json
import os

# File to store expenses
EXPENSE_FILE = 'expenses.json'

# Load existing expenses
def load_expenses():
    if os.path.exists(EXPENSE_FILE):
        with open(EXPENSE_FILE, 'r') as file:
            return json.load(file)
    return []

# Save expenses to file
def save_expenses(expenses):
    with open(EXPENSE_FILE, 'w') as file:
        json.dump(expenses, file)

# Add an expense
def add_expense(expenses):
    description = input("Enter expense description: ")
    amount = float(input("Enter expense amount: "))
    expenses.append({"description": description, "amount": amount})
    save_expenses(expenses)
    print("Expense added.")

# View all expenses
def view_expenses(expenses):
    if not expenses:
        print("No expenses found.")
        return
    print("\nExpenses:")
    for index, expense in enumerate(expenses, start=1):
        print(f"{index}. {expense['description']}: ${expense['amount']:.2f}")

# Delete an expense
def delete_expense(expenses):
    view_expenses(expenses)
    if expenses:
        index = int(input("Enter the index of the expense to delete: ")) - 1
        if 0 <= index < len(expenses):
            removed = expenses.pop(index)
            save_expenses(expenses)
            print(f"Deleted expense: {removed['description']}")
        else:
            print("Invalid index.")

# Main function
def main():
    expenses = load_expenses()
    while True:
        print("\nExpense Tracker")
        print("1. Add Expense")
        print("2. View Expenses")
        print("3. Delete Expense")
        print("4. Exit")
        choice = input("Choose an option: ")

        if choice == '1':
            add_expense(expenses)
        elif choice == '2':
            view_expenses(expenses)
        elif choice == '3':
            delete_expense(expenses)
        elif choice == '4':
            print("Exiting the program.")
            break
        else:
            print("Invalid option. Please try again.")

if _name_ == "_main_":
    main()