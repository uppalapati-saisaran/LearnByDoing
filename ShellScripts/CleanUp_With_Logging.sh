shell scripting: Input/Output and Logging 

Why it matters:
- you often need to log your script's results (e.g., for audits or debugging).
- you also want to take user input (e.g., filenames, email addresses, choices).

Key concepts covered:

1, read - get input from the user
2, echo - print output 
3,  >> append output to a file (logging)
4, tee - write to console and file simultaneously 

#Disk Cleanup and logging 
#!/bin/bash 

LOG_FILE="/var/log/disk_cleanup.log" 

echo "Enter directory to clean:"
read DIR 

echo "Cleaning started at $(date)" | tee -a "$LOG_FILE"
echo "Target directory: $DIR" | tee -a "$LOG_FILE" 

if [ -d "$DIR" ]; then 
    find "$DIR" -type f -name "*.log"  -mtime +7 -exec rm -v {} \;
	| tee -a "$LOG_FILE"
	echo "CleanUp complete. " | tee -a "$LOG_FILE"
	else 
	echo "ERROR: Directory $DIR not found!" | tee -a "$LOG_FILE"
fi

echo "Finished at $(date)" | tee -a "$LOG_FILE" 

 
	
	
