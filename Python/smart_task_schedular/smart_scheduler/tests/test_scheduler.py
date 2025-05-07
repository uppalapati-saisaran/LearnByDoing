import unittest
from datetime import datetime, timedelta
from scheduler.task import Task
from scheduler.scheduler import Scheduler
from scheduler.logger import Logger 

class DummyLogger:
    def __init__(self):
        self.logs = []

    def log(self,message):
        self.logs.append(message)

class TestTask(unittest.TestCase):
    def test_task_run_executes_action(self):
        self.executed = False
    
        def action():
            self.executed = True

        task = Task("TestTask", datetime.now(), action)
        task.run()

        self.assertTrue(self.executed)

class TestScheduler(unittest.TestCase):
    def setUp(self):
        self.logger = DummyLogger()
        self.scheduler = Scheduler(logger=self.logger)

    def test_add_task(self):
        task = Task("Task1", datetime.now() + timedelta(seconds=5), lambda: None)
        self.scheduler.add_task(task)
        self.assertEqual(len(self.scheduler.tasks),1)
        self.assertIn("Task added: Task1", self.logger.logs)

    def test_remove_task(self):
        task = Task("Task2", datetime.now() + timedelta(seconds=5), lambda: None) 
        self.scheduler.add_task(task)
        self.scheduler.remove_task(task)

        self.assertEqual(len(self.scheduler.tasks),1)
        self.assertIn("Task added: Task2", self.logger.logs)

if __name__ == "__main__":
    unittest.main()
