#!/bin/bash 
// It is called a shebang line in a shell script.  ->  she (shi) -> light, bang (bang or hang) -> strong 
// It tells the operating system which interpreter should be used to run the script.
   .#! - Special marker that indicates "use the following program to interpret this file."
   ./bin/bash - Path of the Bash shell executable on most Unix/Linux systems. 

source="/home/user/documents"
backup="/home/user/backups/documents_$(date +%F).tar.gz"
- %F - Equivalent to %Y-%m-%d  ( 2005-08-16 )

tar -czf "$backup" "$source"
# c - create a new archieve -> "ar" sounds like "ahr" "ch" here is pronounced like "k" . "ive" sounds like ive in hive.  stress is on the first first symllable: AHR-kive 
# v - verbose mode: shows the progress in the terminal by listing files being archieved. -> vers sounds like vur bose -> sounds like bohs -> Stress in on second symbollas : vur-BOHS
# f - File. specifies the name of the archive file to be created (must be followed by the filename)
# z = compress the archieve using gzip.


Shedule using cron:
0 2 * * * /home/user/backup_script.sh 
(Runs every day at 2 AM) 


MIN HOUR DAY_OF_MONTH MONTH DAY_OF_WEEK COMMAND  