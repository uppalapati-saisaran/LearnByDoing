#!/bin/bash 

#Directory weher logs are stored
LOG_DIR="/ver/log/myapp"

#Directory to store backups
BACKUP_DIR="/var/log/myapp/backup"

#Date format archieved logs
DATE=$(date +%Y-%m-%d) 

#Ensure backup directory exits
mkdir -p "$BACKUP_DIR"

#Archieve the current log 
tar -czf "$BACKUP_DIR/log_$DATE.tar.gz" "$LOG_DIR"/*.log 

#Empty the original logs
: > "$LOG_DIR/app.log"
: > "$LOG_DIR/error.log" 

#Delete backup older than 4 weeks 
find "$BACKUP_DIR" -name "*.tar.gz" -mtime +28 -exec rn {} \;

echo "Log rotatoin completed on $DATE" 


