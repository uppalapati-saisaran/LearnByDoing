import json 

class Config:
    def __init__(self, filepath):
        self.filepath = filepath
        self.settings = self.load() 

    def load(self):
        with open(self.filepath, 'r') as f:
            return json.load(f)
        
    def get(self,key,default=None):
        return self.settings.get(key,default)    