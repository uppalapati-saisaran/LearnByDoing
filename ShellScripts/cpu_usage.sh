#!/bin/bash 

cpu=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')

if (( $(echo "$cpu > 80" | bc -1) )); then 
  echo "High CPU usage: $cpu% | mail -S "CPU alert" your@gmail.com 
fi 

Schedule using cron:

*/10 * * * * /home/user/cpu_monitor.sh 

(Checks every 10 minutes) 

********************************************************************************************************

What is top?
- top is commmand that shows real-time system stats -- like CPU usage, memory usage, running process etc.
- But by default, it's interactvie (keeps updating until you process q). 

-bn1 - What does it mean?

-b - Batch mode (non-interactive) - for scripting/output to file 
-n 1 - Run 1 iteration and then exit 

top -bn1 
- Run top in batch mode,just once, and then quit. 

***********************************************************************************************************
 
grep "Cpu(s)" 

SampleOuput :

%Cpu(s): 2.0 us, 1.0 sy, 0.0 ni, 95.0 id, 1.5 wa 

What do the fileds mean?

us - User space CPU usage 
sy - System (kernel) CPU usage 
ni - Nice(low-priority) processes 
id - idle (free CPU)
wa - I/O wait 
hi - Hardware interrupts 
si - software interrutps 
st - Stolen time (VMs) 

*********************************************************************************************************** 

swk '{print $2 + $4 }' 

us + ni 

***********************************************************************************************************



