#main.py

from expense_manager import ExpenseManager
from expense import Expense
from storage import Storage

def main():
    manager = ExpenseManager
    storage = Storage() 

    manager.expenses = storage.load() 

    while True:
        print("\n1. Add expenses  \n2. List expenses \n3. Save & Exit")
        choice = input("Enter choice: ")

        if choice == '1':
            try:
                amount = float(input("Amount: "))
                category = input("Category (Food, Travel, etc): ")
                description = input("Description :")
                exp = Expense(amount,category,description)
                manager.add_expenses(exp)
                print("Expenses added!")
            except ValueError:
                print("Invalid amount. Please try again.")

        elif choice == '2':
            for idx, e in enumerate(manager.list_expenses()):
                print("f{idx + 1}. {e.amount} | {e.category} | {e.description} | {e.date.strftime('%Y-%m-%d')}") 

        elif choice == '3':
              storage.save(manager.expenses)
              print("Expenses saved. Good bye!")
              break
        else:
            print("Invalid choice!")

if __name__ == '__main__':
    main() 