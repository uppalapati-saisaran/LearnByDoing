from datetime import datetime, timedelta 
from scheduler.task import Task
from scheduler.scheduler import Scheduler 
from scheduler.logger import Logger
from scheduler.config import Config

def sample_action():
    print("This is a sample task!")

config = Config("config.json")
logger = Logger("task_log.txt")
scheduler = Scheduler(logger)

task = Task(
    name="Say Hello",
    schedule_time=datetime.now() + timedelta(second=6),
    action=sample_action
)

scheduler.add_task(task)
scheduler.run()

