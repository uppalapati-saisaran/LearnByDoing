import time
from datetime import datetime

class Scheduler:
    def __init__(self, logger):
        self.tasks = []
        self.logger = logger 
    
    def add_task(self, task):
        self.tasks.append(task)
        self.logger.log(f"Task added: {task.name}" )

    def remove_task(self,task_name):
        self.tasks = [ t for t in self.tasks if t.name != task_name]
        self.logger.log(f"Task removed : {task_name.name}")

    def run(self):
        while True:
            now = datetime.now()
            for task in self.tasks:
                if now >= task.schedule_time:
                    task.run()
                    self.logger.log(f"Task executed: {task.name}")
                    if not task.recurring:
                        self.remove_task(task.name)
            time.sleep(1) 


