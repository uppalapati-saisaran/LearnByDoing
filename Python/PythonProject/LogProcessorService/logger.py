import threading
import datetime 
from typing import Optional

class Logger:
    
    """
    A thread-safe logger class that writes logs to console and file.
    Implements a Singletho pattern. 
    """
    _lock = threading.Lock()  # Ensures thread safe writes.
    _log_file = "application.log" # Log file name 
    _instance = None # Singleton instance 

    def __new__(cls):
        """
        Ensures only one logger instance exists (Singleton pattern).
        """
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance 

    @staticmethod
    def _get_timestamp() -> str:
        """Return formatted current timestamp."""    
        return datetime.datetime.now().strftime("%Y-%m-%d %H-%M-%S")
    
    @staticmethod 
    def _write(level: str,message: str) -> None:
        """Internal method to write logs safely and consistently"""
        with Logger._lock:
            