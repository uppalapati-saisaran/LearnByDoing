from multiprocessing import Process, Queue, current_process
# Process -> lets us create a separate CPU process
# Queue -> safe communication between main thread & process
# current_process() -> returns name/id of running process.
import time 
from logger import Logger
from utils import timing 
# -> this decorator will measure how long each log analysis takes.
# -> Shows advanced Python: decorators, Introspection. 

class LogProcessor(Process):
# -> We create a custom process class.
# -> This is the OOP way to design multiprocessing.
    """
    A dedicated CPU bound process that performs heavy analysis on log messages.
    Inherits from multiprocessing.Process
    """
    def __init__(self, task_queue: Queue):
        super().__init__()
        #-> initilaizes the Parent Process class
        self.task_queue = task_queue 
        #-> task_queue holds incoming log messages.

    @timing 
    # -> measures how long the function takes.
    def analyze_log(self, message:str) -> None:
        """Simulate heavy CPU work (e.g,. text analysis). """
        time.sleep(1) # Pretent heavy calculation.
        #-> We simulate CPU-intensive work using above. 
        word_count = len(message.split())
        Logger.info(f"{current_process().name} processed log: '{message}' | words: {word_count}")

    def run(self) -> None:
    # -> Every process has a run() method.
    # -> This code runs inside the separate CPU processes.
        """Process loop - keeps waiting for messages from queue."""
        Logger.info(f"{current_process().name} started.")

        while True:
            message = self.task_queue.get()

            if message == "STOP":
                Logger.info(f"{current_process().name} stopping.")
                break 
            self.analyze_log(message)  