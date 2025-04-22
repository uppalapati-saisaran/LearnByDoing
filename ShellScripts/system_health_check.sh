#!/bin/bash
echo "System Health Report"
echo "--------------------"
echo "Uptime: $(uptime -p)"
echo "CPU Load: $(uptime | awk -F'load average:' '{ print $2 }')" 
echo "Free Memory: $(free -h | grep Mem | awk '{print $4}')"
echo "Disk Usage:"
df -h 

