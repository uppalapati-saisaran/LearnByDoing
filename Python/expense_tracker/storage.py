import csv
import os
from expense import Expense

class Storage:
    def __init__(self, filename):
        self.filename = filename 

    def save_expense(self, expense):
        with open(self.filename,'a',newline='') as f:
            writer = csv.writer(f)
            writer.writerow(expense.to_list()) 

    def load_expenses(self):
        if not os.path.exists(self.filename):
            return []
        with open(self.filename, 'r') as f:
            reader = csv.reader(f)
            return [Expense.from_list(row) for row in reader ]