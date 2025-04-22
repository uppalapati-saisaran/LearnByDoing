#!/bin/bash 

#directory backup script 

#source and backup directories 

SOURCE_DIR = "$HOME/Documents"
BACKUP_DIR = "$HOME/Backups" 

DATE=$(date +%Y-%m-%d_%H-%M-%S)

BACKUP_FILE = "$BACKUP_DIR/backup_$DATE.tar.gz" 

#Create backup directory if not exists
mkdir -p "$BACKUP_DIR"

#Create the backup 
tar -czf "$BACK_FILE" "$SOURCE_DIR" 

#Logging 
if [ $? -eq 0 ]; then 
    echo "[$DATE] Backup successful: $BACKUP_FILE" >> "$BACKUP_DIR/backup.log" 
else
    echo "[$DATA] Backup failed" >> "$BACKUP_DIR/backup.log" 

	
