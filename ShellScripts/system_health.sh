USe Case:

You want a script to:
- Check disk usage 
- Check CPU load
- Check memory usage 
- Send alerts if thresholds are crossed

#!/bin/bash

DISK_THRESHOLD=80
CPU_THRESHOLD=75
MEM_THRESHOLD=80

#Function to check disk usage 
check_disk_usage() {
     USAGE = $(df / | tail -1 | awk '{print $5}' | sed 's/%//') 
	 
	 if [ "$USAGE" -gt "$DISK_THRESHOLD"]; then 
	    echo "ALERT: Disk usage is at "$USAGE%"
     else
	    echo "Disk usage OK: #USAGE%"
	 fi 
}

#Function to check CPU load (1-minute average)
check_cpu_load() {
     LOAD=$(uptime | awk -F'load average:' '{print $2}' | cut -d'.' -f1 | awk '{print int($1)}'
	 
	 if [ "$LOAD" -gt "$CPU_THRESHOLD" ]; then 
	     echo "ALERT: CPU load is high: $LOAD"
	 else
	     echo "CPU load Ok: $LOAD"
	 fi 
}

#Function to check memory usage 
check_memory_usage() {
     USED=$(free | grep Mem | awk '{print int($3/$2 * 100)}')
	 if [ "$USED" -gt "$MEM_THRESHOLD" ]; then 
	     echo "ALERT: Memory usage is at $USED%"
	 else
	     echo "Memory usatte OK: $USED%"
	 fi 
}

#Master function to run all checks 
run_health_check() {
  echo "=== System Health Check ==="
  check_disk_usage
  check_cpu_load
  check_memory_usage
  echo "============================"
}

#Execute 
run_health_check 

# sed 's/%//';  This is a sed command that removes that %symbol from the string 8.5%

s - substitue command
/%/ - The pattern to search for: a literal percent sign 
/ / - Replace ti with nothing (i.e., remove it) 


#  we use int(...) to get just the integral part.
