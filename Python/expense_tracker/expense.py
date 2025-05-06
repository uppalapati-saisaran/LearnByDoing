# expense.py
import datetime 

class Expense:
    def __init__(self,amount,category,note,date=None):
        self.amount = float(amount)
        self.category = category
        self.note  = note
        self.date = date or datetime.date.today().isoformat()

    def to_list(self):
        return [self.date, self.category, f"{self.amount:.2f}", self.note]
    
    @staticmethod
    def from_list(data):
        return Expense(data[2],data[1],data[3],data[0]) 