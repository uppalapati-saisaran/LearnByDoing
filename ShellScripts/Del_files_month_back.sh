#!/bin/bash 
log_folder="/ver/log/myapp"

find "$log_older" -type -f -mtime +30 -exec rm {} \;
