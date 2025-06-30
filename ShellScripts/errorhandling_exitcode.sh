#!/bin/bash 
set -euo pipefail 

1. -e (exit on error) - The script exits immediately if any command fails(i.e., returns a non-zero exit code)
                      - Prevents the script from continuing after a failure. 
					  
2. -u (unset variable error) - The script exists with an error if you try to use an undefined variable.
                             - helps catch typos or missing input.
							 
3. -o pipefail : In a pipeline(cmd1 | cmd2), this causees the script to fail if any command in the pipeline fails, not just the last one.

#Variables.
SOURCE_DIR="/home/user/documents"
BACKUP_DIR="/home/user/backup"
TIMESTAMP=$(date + '%Y%m%d_%H%M%S")
LOG_FILE="/var/log/backup.log"
ARCHIVE_NAME="backup_$TIMESTAMP.tar.gz"

log() {
   echo "[$(date)] $1" | tee -a "$LOG_FILE"
}

#Check if source exists
if [ ! d "$SOURCE_DIR" ]; then 
   log "Error: Source Directory $SOURCE_DIR does not exist."
   exit 1
fi 

#Ensure backup directory exists
mkdir -p "$BACKUP_DIR"

#Perforce backup 
log "Starting backup of $SOURCE_DIR..."
tar -czf "$BACKUP_DIR/$ARCHIEVE_NAME" "$SOURCE_DIR" || {
   log "Error: Failed to create archieve."
   exit 2 
}

log "Backup successful : $BACKUP_DIR/$ARCHIEVE_NAME"

exit 0 

