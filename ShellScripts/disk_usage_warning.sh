#!/bin/bash
THRESHOLD=80

df -H | grep '^C:/Program Files/' | while read line; do 
    USAGE=$(echo $line | awk '{print $5}' | sed 's/%//g')
	if [ "$USAGE" > "$THRESHOLD" ]; then 
	    echo "Disk usage warning: $line : $USAGE"
	else
	    echo "No Disk usage warning: $USAGE"
	fi
done 
                         
what does df do?
- df stands for disk free - it shows how much disk space is used and available on mounted filesystems. 
- df -H - Human-readable with powers of 1000 (e.g., MB = 1000 KB) 
- Shows sizes in KB,MB,GB using decimal units 

sed 's/%//g' 

- This sed expression removes all percent signs(%) from the input text.
Breakdown 

- s - substitute 
- /%/ - the target pattern: percent symbo % 
- / / - replace it with nothing (i.e., delete it) 
- g - global: apply to all % in each line 


