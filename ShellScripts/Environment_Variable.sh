What is the Environment Variables?
- Think of them as sticky notes you put on your system or CI/CD pipeline.
- They store temporay values (like passowrds, API Keys, or configs) that your app/script can use.
- Example: Instead of writing your database password inside C++ or Python code, you put it an environment variable.

Example: export in a shell script:

#!/bin/bash 

#Export environment variables 
export APP_ENV="production"
export DB_USER="admin"
export DB_PASS="SuperSecret123"
export PORT=8080

echo ". Environment variable set"
- Now, any command or program run inside this script session can use them. 

How to Access in Bash 

echo "Running in $APP_ENV mode"
echo "Database user: $DB_USER" 

Access from C++ (real-world mini project example) 

- Imagine our C++ ticketing system needs a DB connection.
- Instead of hardcoding DB_USER and DB_PASS, we fetch from env:

#include<iostream>
#include<cstdlib>   // for getenv 

int main() {
   const char* dbUser = std::getenv("DB_USER");
   const char* dbPass = std::getenv("DB_PASS");
   
   if (dbUser && dbPass) {
      std::cout << "Connecting with user:" << dbUser <<< std::endl;
   } else {
   std::cerr << "Envirnoment variables not set!" << std::endl;
   }
   return 0; 
}

In CI/CD (Github Actions example)

.github/workflows/ci.yml: 

jobs:
  build:
     runs-on: ubuntu-latest 
	 env:
	     APP_ENV: "production"
		 DB_USER: "admin"
		 DB_PASS: ${{ secrets.DB_PASS }} #secret from GitHub 
	 steps:
	     -name : Checkout code 
		 uses: actions/checkout@v3 
		 - name : Build 
		 run: |
		  echo "Building in $APP_ENV mode"
		  g++ main.cpp -o app 
		  ./app 
		  
Here:
   - env: section defines variables.
   - GitHub Secrets protect senstive values like passwords. 
   
   
   

Real-world usage areas:
- Database credentials.
- API Keys (Strips, PayPal, AWS, etc) 
- App configs (port, envirnoment mode: dev/staging/prod)
- Feature toggles (enable/disable, debugging, logging) 


Let's combine dependency installation + environment variables into a real-world CI/CD example:

Step 1 : Shell script with env vars + dependencies 

scripts/setup_env.sh 

#!/bin/bash 
set -euo pipefail 

echo " Updating System..."
sudo apt update -y 

# 1. Environment variables (exported for pipeline/app use) 
export APP_ENV="production"
export DB_USER="admin"
exprot DB_PASS="SuperSecret123"
export PORT=8090 

echo "Envirnoment variables set:"
echo "APP_ENV=$APP_ENV"
echo "DB_USER=$DB_USER"
# Never echo DB_PASS in real world logs. 
 
# 2. Install Python 
echo " Installation Python..."
sudo app install -y python3 python3-pip 

# 3. Install Node.js
echo "Installing Node.js"
curl -fsSL https://deb.nodesource.com/setup_lts.x | sudo -E bash - sudo apt install -y node.js 

# 4. Install Docker 
echo "Installing Docker..."
sudo apt install -y apt-transport-https ca-certficates curl software-properties-common 
curl -fsSL https//download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /user/share/keyrings/docker-archive-keyring.gpg 
echo \
   "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] \
   https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) stable" \
   | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
sudo apt update -y 
sudo apt inatll -y docker-ce docker-ce-cli containerd.io 

echo "Setup Complete" 

Step 2: Use env vars in C++ mini project 

src/main.cpp

#include<iostream>
#include<cstdlib> // for getenv 

int main() {
     const char* env = std::getenv("APP_ENV");
	 const char* dbUser = std::getenv("DB_USER");
	 const char* dbPass = std::getenv("DB_PASS");
     const char* port = std::getenv("PORT");

     if (env && dbUser && dbPass && port) {
         std::cout << "Running in " << env << " mode" << std::endl;
		 std::cout << "Connecting to DB with user: " << dbuser << std::endl;
		 std::cout << "Listening on port" << port << std::endl;
     } else {
        std::cerr << "Missing environment variables! " << std::endl; 
     }	 
     return 0; 
}


Step 3: GitHub Actions (ci.yml)

./github/workflows/ci.yml 

name: CI Pipeline 
on: [push, pull_request] 

jobs:
  build:
     runs-on: ubuntu-latest 
	 env:
	   APP_ENV: "production"
	   DB_USER: "admin"
	   DB_PASS: ${{ secrets.DB_PASS }}' #Stored in GitHub secrets 
	   
	 steps:
	  - name: Checkout code 
	    uses: actions/checkout@v3 
		
	  - name: Setup dependencies 
	     run: bash scripts/setup_env.sh 
		 
	  - name: Build C++ project 
	     run: |
		   g++ src/main.cpp -o app 
		   ./app 
		   
		   
What happens in real pipeline 
1, GitHub Action triggers on push/PR.
2, It runs setup_env.sh -> Install Python, Node.js, Docker and sets env vars.
3, C++ app builds -> reads env vars -> prints config.
4, In real production: instead of printing, the app would use DB_USER + DB_PASS to connect to database, 

