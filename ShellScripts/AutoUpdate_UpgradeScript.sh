#!/bin/bash
// It is called a shebang line in a shell script.  ->  she (shi) -> light, bang (bang or hang) -> strong 
// It tells the operating system which interpreter should be used to run the script.
   .#! - Special marker that indicates "use the following program to interpret this file."
   ./bin/bash - Path of the Bash shell executable on most Unix/Linux systems. 
   
sudo apt update && sudo apt upgrade -y 
// sudo - It's short for superuser do.
// Lets a regular user run commands as another user (usually the root superuser) with elevated privileges.
// It's safer than logging in as root directly because it can be limited and audited.

apt update 
// Runs apt udate with root permissions so it can modify system files.

Key points:
1. Password prompt 
   The first time you run sudo in a session, it asks for your password (not root's) - assuming you're in the sudoers list.
   
2. /etc/sudoers file -> "soo" (like is super) , "do" -> "doo" (like in do something) , "ers" -> "ers" SOO-doo-ers 
   This config file controls who can use sudo, and for what commands.
   Edit it using:
   sudo vi sudo 
   
3. Run as another user 
   You can also specify a different user:
   sudo -u username command 
   
4. Root shell 
   To get a tempoaray root shell: 
   sudo -i 
   
Be careful: sudo commands can change system files, delete data, or break the OS if misused. 
 
 - it's safter then just using su. 
 
1. When you type a sudo command 
 Example:
      sudo apt update 
	  
Steps:
1. sudo binary executes 
   The program /usr/bin/sudo (or similar) starts. 
   
2. Determines your identity 
   - Gets your username and UID (user ID) from the OS. 
   - Reads your groups from /etc/group. 
   
2.  Checking permissions (/etc/sudoers) 
   - sudo reads /etc/sudoers (and sometimes /etc/sudoers.d/*) to see:
     . Are you allow to run sudo at all?
	 . Which commands are you allowed to run?
	 . Does it require a password?
   - This is done using the libsudo_util library and poilcy plugin.

Example: /etc/sudoers snippet: ( snip-> like the word snip, et -> sounds like it. Stress is on the first syllable: SNIP-it). 

sai  ALL=(ALL:ALL) ALL 
// This means user sai can run any command as any user on any host.

   
3. Password Authenticaion: 

- If you sudo policy says so, sudo will prompt for your password.
- The password is verified against PAM (Pluggable Authenticaion Modules), not the sudo program directly.
- PAM (Plugggable Authentication Modules) checks you credentials using /etc/shadow without giving sudo access to your password in plain text. 

4. Session timestamping 

- Once you enter your password, sudo stores a timestamp in /var/lib/sudo or /run/sudo/ts 
- This timestamp means you won't need to enter the password again for a set timeout(usally 5 - 15 minutes) 

5. Privilege escalation (setuid) 

Here's the key magic:
. The sudo binary has the setuid bit set and is owned by root: 

_rwsr_xr_x 1 root root 163k /usr/bin/sudo 
. Setuid means what when you run sudo, it executes as root, no matter who runs it. 
. After permission checks, sudo:
      . Changes its effective UID to 0 (root).
	  .Execute the target command with those privileges. 
	  
6, Environment sanitization 
   // en -> like en;    vy - rhymes with my; ruhn -> like run;  ment-> likemuhnt or ment; 
   // San -> san, i -> short i , tuh -> soft tuh sound , zay -> rhymes with say, shun -> like shun in caution. 
. Before running the commad, sudo, cleans and restricts envirnoment variables to prevent privilege abuse.
. It sets safe defaults like:
     PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin 
	 
7, Command execution 
. Finally, sudo calls execve() to replace its process with your target command (apt update), now running as root.
. When the command finishes, you're back to your normal user shell. 

8, logging
- Every sudo attempt (success or failure) is logged to /var/log/auth.log or vi journalctl.
- This helps system admins track who ran what. 

sudo is basically:
1, Policy check -> Am I allowed?
2, Authenticaion -Prove it's me 
3. Privilege escalation -> Switch UID to root ( es -> like es; luh -> soft kuh sound; lay->rhymes with day; shun->like shun in caution) 
4, Execute securely -> Clean environment + run 
5, Log -> Record the action: 


*********************************************************************************************************************************






	 