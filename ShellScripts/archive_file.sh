#!/bin/bash 

source="/home/user/documents"
backup="/home/user/backups/documents_$(date +%F).tar.gz"

tar -czf "$backup" "$source"
# c - create a new archieve
# v - verbose mode: shows the progress in the terminal by listing files being archieved.
# f - File. specifies the name of the archive file to be created (must be followed by the filename)
# z = compress the archieve using gzip.


Shedule using cron:

0 2 * * * /home/user/backup_script.sh 
(Runs every day at 2 AM) 


