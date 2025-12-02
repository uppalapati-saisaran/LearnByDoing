import time 
import threading # our module is thread-based 
from queue import Queue # self communication to processes 
from typing import List 
from logger import Logger # the logging system you built 
from utils import retry # advanced decorator used for unstable reads 

class LogReader(threading.Thread): 
    """
    We inherit from Thread -> real world, OOP-based design 
    used in: log ingestion pipelines, real-time monitoring, stream readers, message brokers
    """
    """
    A thread that reads log messages (simulated) and pushes them into a queue,
    this acts as a 'producer' in a producer-consumer patter.
    """
    def __init__(self, task_queue:Queue, messages: List[str],delay: float = 0.5):
        super().__init__(daemon=True) # Daemon thread -> auto kill on program exit 
        """
        daemon = True -> thread stops automatically when main program exits.
        task_queue -> sending messages to process
        messages -> our simulated log list 
        delay -> interval between messages 
        """
        self.task_queue = task_queue
        self.messages = messages
        self.delay = delay 
        self._stop_event = threading.Event() # used to gracefully stop thread 
        # Stop Mechanism : Event objects are the professional, remcommanded way to stop threads gracefully. 

    def stop(self):
        """Signal to stop the thread gracefully"""
        Logger.info("LogReader stop signal received.")
        self._stop_event.set()
        # This avoids: killing threads, corrupting data, stuck loops 

    @retry(times=3,delay=0.2)
    def read_message(self,msg: str) -> str:
        """
        Simulates reading log messages.
        Decorated with retry: if somehing goes wrong while reading.
        retry up to 3 times
        """
        if "ERROR" in msg:
            raise Exception("Simulated read error") # Test retry behaviour 
        return msg 
    
    def run(self):
        """Main thread loop that pushes messages to the task queue."""
        Logger.info("LogReader thread started.")

        for msg in self.messages:
            if self._stop_event.is_set():
                Logger.info("LogReader stopping gracefully")
                break 

            try:
                processed = self.read_message(msg)
                self.task_queue.put(processed) 
                Logger.info(f"Log Reader queue message: {processed}")

            except Exception as e:
                Logger.error(f"Failed to read message after retries: {e}")

            time.sleep(self.delay)

        Logger.info("LogReader finished")



