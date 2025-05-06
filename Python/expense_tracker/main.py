#main.py

from expense_manager import ExpenseManager
from storage import Storage

def main():
    storage = Storage("expenses.csv") 
    manager = ExpenseManager(storage)

    while True:
        print("\n1. Add expenses  \n2. View Expenses \n3. View Total \n4. Exit")
        choice = input("Enter choice: ")

        if choice == '1':
            try:
                amount = float(input("Amount: "))
                category = input("Category (Food, Travel, etc): ")
                description = input("Description :")
                manager.add_expense(amount,category,description)
                print("Expenses added!")
            except ValueError:
                print("Invalid amount. Please try again.")

        elif choice == '2':
            expenses = manager.get_all_expense()
            print(f"\n{'Date':<12} {'Category':<15} {'Amount':<10} Note")
            print("-" * 50)
            for e in expenses:
                print(f"{e.date:<12} {e.category:<15} {e.amount:<10.2f} {e.note}")
 
        elif choice == '3':
            total = manager.get_total_expense()
            print(f"Total Expenses: ${total: .2f}")
              
        else:
            print("Invalid choice!")
            break 

if __name__ == '__main__':
    main() 