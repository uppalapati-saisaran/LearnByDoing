#!/bin/bash
LOG_FILE = "/var/log/syslog"
KEYWORD="error"

tail -n 100 "$LOG_FILE" | grep -i "$KEYWORD" > /tmp/error_report.txt 

if [ -s /tmp/error_report.txt ]; then 
# -s checks if the file exists and has a non-zero size (i.e., not empty)
    echo "Errors found in syslog!" | mail -s "Error Report" your@email.com 
fi 


