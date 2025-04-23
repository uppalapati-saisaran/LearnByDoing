#expense_manager.py 
from expense import Expense 
class ExpenseManager:
    def __init__(self):
        self.expenses = []

    def add_expenses(self, expense: Expense):
        self.expenses.append(expense) 

    def list_expenses(self):
        return self.expenses 
