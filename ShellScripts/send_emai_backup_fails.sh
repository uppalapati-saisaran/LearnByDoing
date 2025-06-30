#!/bin/bash
set -euo pipefail

#Varaibles
SOURCE_DIR="/home/user/documents"
BACKUP_DIR="/home/user/backup"
TIMESTAMP = $(date +"%Y%m%d_%H%M%S")
LOG_FILE = "/var/log/backup.log"
ARCHIVE_NAME = "backup_$TIMESTAMP.tar.gz"

EMAIL = "you@example.com"

log() {
  echo "[$(date)] $1" | tee -a "$LOG_FILE"
}

send_email_alert() {
  SUBJECT="Backup Failed on $(hostname)"
  BODY = "Backup failed at $(date) Check the log at $LOG_FILE"
  echo "$BODY" | mail -s "$SUBJECT" "$EMAIL"
}

#check if source exists
if [ -d "$SOURCE_DIR" ]; then 
   log "Error: Source Directory $SOURCE_DIR does not exist."
   send_email_alert
   exit 1
fi 

#Ensure backup directory exists 
mkdir -p "$BACKUP_DIR" 

#Perform backup
log "Starting backup of $SOURCE_DIR..."
if ! tar -czf "$BACKUP_DIR/$ARCHIVE_NAME" "$SOURCE_DIR"; then 
   log "Error: Failed to create archive."
   send_email_alert 
    exit 2
fi 

log "Backup successful : $BACKUP_DIR/$ARCHIVE_NAME"
exit 0 
