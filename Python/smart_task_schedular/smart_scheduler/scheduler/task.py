class Task:
    def __init__(self,name,schedule_time, action, recurring=False):
        self.name = name 
        self.schedule_time = schedule_time 
        self.action = action
        self.recurring = recurring 

    def run(self):
        print(f"Running task: {self.name}")
        self.action() 
