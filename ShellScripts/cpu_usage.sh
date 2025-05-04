#!/bin/bash 

cpu=$(top -bn1 | grep "Cpu(s)" | awk '{print $2 + $4}')

if (( $(echo "$cpu > 80" | bc -1) )); then 
  echo "High CPU usage: $cpu% | mail -S "CPU alert" your@gmail.com 
fi 

Schedule using cron:

*/10 * * * * /home/user/cpu_monitor.sh 

(Checks every 10 minutes) 

