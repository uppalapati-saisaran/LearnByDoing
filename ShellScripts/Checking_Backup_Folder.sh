#!/bin/bash

watch_folder = "/home/user/important"
backup_folder = "/home/user/backup"

mkdir -p "$backup_folder"

while true 
do 
  new_files=$(find "$watch_folder" -type -f -mmin -1)
  
  if [ ! -z "new_files" ]; then 
      echo "New file detected, backing up..."
	  cp -r "$watch_folder"/* "$backup_folder"/
  fi 
  
  sleep 60
done 

Explanation:

* find ... -mmin -1 -> finds files modified in the last 1 minute.

* -z checks if the list is empty 

* sleep 60 -> checks every 1 minute

Use case: Automatic backup system 


********************************************************************


What is a Cron Job?

- Cron is a Linux/Unix tool that schedule tasks(like your scripts) to run automaticaly at set times.
- A "cron tab" is  just a scheduled command or script.

How to Create a Cron job 

Step1 : Open you Crontabl file 

crontab -e 

- crantab = cron table 
- -e = edit 

First time , it may ask you to select an editor (choose nano for easy editing) 

Step 2: Add your schedule and command 

The format inside crontab looks like:

* * * * * command_to_run 

1st - Minutes ( 0-59 )
2nd - Hours ( 0-23 )
3rd - Day of Month (1-31)
4th - Month (1-12)
5th - Day of week (0-7) ( 0 or 7 = sunday) 


