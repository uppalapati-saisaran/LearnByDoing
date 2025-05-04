#!/bin/bash 

if [ ! -d "/home/user/newfolder" ]
   mkdir /home/user/newfolder 
   echo "Folder created!"
else
   echo "Folder already exist."
done 

Explanation:

*   -d -> checks if a directory exists.
*  ! -d -> NOT exists 
* mkdir -> create directory 

Use case : Safer Scripting, avoid errors.




