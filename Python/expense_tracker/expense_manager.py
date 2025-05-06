from expense import Expense
from storage import Storage 

class ExpenseManager:
    def __init__(self,storage):
        self.storage = storage 

    def add_expense(self,amount,category,note):
        expense = Expense(amount,category,note)
        self.storage.save_expense(expense) 

    def get_all_expense(self):
        return self.storage.load_expenses() 
    
    def get_total_expense(self):
        return sum(exp.amount for exp in self.get_all_expense()) 
    
