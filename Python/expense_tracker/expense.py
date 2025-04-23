# expense.py
from datetime import datetime 

class Expense:
    def __init__(self,amount,category,description,date=None):
        self.amount = amount
        self.category = category
        self.description = description
        self.date = date or datetime.now()

    def to_dict(self):
        return {
            'amount' : self.amount,
            'category' : self.category,
            'description': self.description,
            'date' : self.date.isoformat() 
        }
    
    @staticmethod
    def from_dict(data):
        return Expense(
            amount=data['amount'],
            category=data['category'],
            description=data['description'],
            date = datetime.fromiosformat(data['date'])
        )