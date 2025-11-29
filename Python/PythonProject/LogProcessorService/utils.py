import time 
# time -> measure execution time.
from functools import wraps
# wraps -> keeps original function name in decorators
from typing import Callable, Any, TypeVar 
# typing -> professional code standard
# TypeVar -> allows decorators to return any type

T = TypeVar("T")  # Generic type for decorators.

# 1. Timing Decorator 
def timing(func: Callable[...,T]) -> Callable[...,T]:
    """
    Decorator that measures how long a function takes.
    Used for performance monitoring.
    """
    @wraps(func)
    def wrapper(*args,**kwargs) -> T:
        start = time.time()
        result = func(*args,**kwargs)
        end = time.time()

        from logger import Logger 
        Logger.debug(f"{func.__name__} executed in {(end-start):.4f} seconds")
    return wrapper 

#2. Retry Decorator 
def retry(times: int = 3,delay: float = 1.0):
    """
    Retries a function multiple times if it fails.
    Useful in real sysems for unstable operations (network,I/O)
    """
    def decorator(func: Callable[...,T]) -> Callable[...,T]:
        @wraps(func)
        def wrapper(*args,**kwargs) -> T:
            from logger import Logger 
            for attempt in range(1,times+1):
                try:
                    return func(*args,**kwargs)
                except Exception as e:
                    Logger.error(f"Attempt {attempt} failed: {e}")
                    time.sleep(delay)
            raise Exception(f"Function {func.__name__} failed after {times} retries.")
        return wrapper 
    return decorator 

#3. Context Manager 
class SafeFileWriter:
    """
    Context manager that safely writes text to a file.
    Ensures file closes even if error happens.
    """
    def __init__(self,filename: str):
        self.filename = filename 
        self.file = None 

    def __enter__(self):
        self.file = open(self.filename,"a")
        return self.file 
    
    def __exit__(self,exc_type,exc,traceback):
        if self.file:
            self.file.close() 
        return False # propagate errors 
    

    