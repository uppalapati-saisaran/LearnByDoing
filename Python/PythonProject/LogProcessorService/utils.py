import time 
from functools import wraps
from typing import Callable, Any, TypeVar 

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
