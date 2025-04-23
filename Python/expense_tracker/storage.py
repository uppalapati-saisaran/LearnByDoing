import json 
from expense import Expense

class Storage:
    FILE = 'expenses.json' 

    def save(self,expenses):
        with open(self.FILE,'w') as f:
            json.dump([e.to_dict() for e in expenses],f,indent=2) 

    def load(self):
        try:
            with open(self.FILE,'r') as f:
                data = json.load()
                return [Expense.from_dict(item) for item in data] 
        except FileNotFoundError:
            return []