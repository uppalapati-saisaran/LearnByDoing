from utils import timing, retry, SafeFileWriter 
from logger import Logger 
import time

@timing 
def slow_function():
    time.sleep(1)
    return "done"

@retry(times=3,delay=0.2)
def unstable():
    raise Exception("Failed intentionally")

Logger.info(slow_function()) 

try:
    unstable()
except Exception as e:
    Logger.error(str(e))

with SafeFileWriter("temp.txt") as f:
    f.write("Hello world!\n")




