#!/bin/bash
#Simple system info menu tool 

while true; do 
   echo "======================================="
   echo "  System Utility Menu  "
   echo "=======================================" 
   
   echo "1. Show current date and time"
   echo "2. Show disk usuage"
   echo "3. Show memory usage"
   echo "4. Show logged-in users"
   echo "5. Exit"
   echo "---------------------------------------"
   read -p "Choose an option [1-5]: " choice 
   
   case $choice in
        1) 
		  echo "Date & Time: $(date)"
		  ;;
		2) 
		  echo "Disk Usage:"
		  df -h
		  ;;
		3)
		  echo "Memory Usage:"
		  free -h
		  ;;
		4) 
		  echo "Logged in users";
		  who
		  ;;
		5) 
		 echo "Exiting... Good bye!"
		 break;
		 ;;
		*) 
		echo "Invalid option. Please choose 1-5."
		;;
	esac 
	
	echo ""
	read -p "Press [Enter] to continue..."
	clear 
  done
		 
		 