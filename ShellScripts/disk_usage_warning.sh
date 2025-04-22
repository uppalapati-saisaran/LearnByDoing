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
                         
