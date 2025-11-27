import threading
# to make logger thread-safe
import datetime 
# for timestamps
from typing import Optional
# adds professional type hits

class Logger:
# We create a wrapper class for logging --- Real projects ALWAYS wrap logs in a class.     
    """
    A thread-safe logger class that writes logs to console and file.
    Implements a Singletho pattern. 
    """
    _lock = threading.Lock()  # Ensures thread safe writes.
    # Prevents two threads from printing at the same time
    # Without this -> logs get jumbled.
    _log_file = "application.log" # Log file name 
    # All logs wil be saved here.
    # Automatically created if missing.
    _instance = None # Singleton instance
    # Used for Singleton pattern only 1 logger instance exists in the entire app. 

    def __new__(cls):
    # This is very advanced python.
    # Controls object creation. We override it so the class creates only ONE logger.
    # This prevent: multiple log files, inconsistent formatijng, race conditions.    
        """
        Ensures only one logger instance exists (Singleton pattern).
        """
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance 

    @staticmethod
    def _get_timestamp() -> str:
    # Standard format used in production logs.
        """Return formatted current timestamp."""    
        return datetime.datetime.now().strftime("%Y-%m-%d %H-%M-%S")
    
    @staticmethod 
    def _write(level: str,message: str) -> None:
    # This method: 1.Lock (thread-safe) 2.Formats timestamp + message 3. Colors ouput 4. Writes to file.
        """Internal method to write logs safely and consistently"""
        with Logger._lock:
            timestamp=Logger._get_timestamp()
            formatted = f"[{level}{timestamp}] {message}"

            #Print to console with color based on level 
            if level == "INFO":
                print(f"\033[92m{formatted}\033[0m") # Green
            elif level == "ERROR":
                print(f"\033[91m{formatted}\033[0m") # Red 
            elif level == "DEBUG":
                print(f"\033[94m{formatted}\033[0m") #Blue 

            #Append the log file.
            with open(Logger._log_file,"a") as f:
            #Append mode -> does not overwrite.
            #Every log saved permanently. 
                f.write(formatted + "\n")
    
    @staticmethod 
    def info(message: str) -> None:
        Logger._write("INFO",message)

    @staticmethod
    def error(message: str) -> None:
        Logger._write("ERROR",message)

    @staticmethod 
    def debug(message: str) -> None:
        Logger._write("DEBUG",message)

                        