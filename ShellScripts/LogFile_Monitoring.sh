#!/bin/bash
LOG_FILE = "/var/log/syslog"
KEYWORD="error"

tail -n 100 "$LOG_FILE" | grep -i "$KEYWORD" > /tmp/error_report.txt 

if [ -s /tmp/error_report.txt ]; then 
    echo "Errors found in syslog!" | mail -s "Error Report" your@email.com 
fi 
