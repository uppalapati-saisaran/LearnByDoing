from queue import Queue 
from log_reader import LogReader 
from time import sleep 

message = ["INFO START","DEBUG step1","ERROR Issue","INFO Finish"]
q = Queue() 

reader = LogReader(q,message)
reader.start() 

sleep(3) 
reader.stop() 

while not q.empty():
    print("From Queue:",q.get())





