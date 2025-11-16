Linux shell scripting used in production to install dependencies like Python, Node.js, and Docker in a reliable, repeatable way.

This is exactly what's done in real CI/CD pipelines and server setup automation. 

Example: install_deps.sh 

#!/bin/bash 
set -e #Exit immediately on error
set -u # Treat unset variables as error
set -o pipefail # Fail if any part of a pipeline fails
 
echo " Updating system..."
sudo apt update -y && sudo apt upgrade -y 

#Install Python 
echo "..Inatlling Python.."
sudo apt install -y python3 python3-pip python3-venv 

#Install Node.js (LTS versoin)
echo " Installing Node.js..."
curl -fsSL http://https://deb.nodesource.com/setup_Its.x | sudo -E bash - 
sudo apt install -y nodejs 
node -v 
npm -v 

#Install Dockter 
echo "Installing Docker..."
sudo apt install -y apt-transport-https ca-certficates curl software-properities-common 
curl -fsSL http://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /user/share/keyrings/docker-archive-keyring.gpg 
echo \ 
   "deb [arch=$(dpkg --print-architecture) signed-by=/user/share/keyrings/docker-archive-keyring.gpg] \
   https://download.docker.com/linux/ubuntu \
   $(lsb_release -cs) stable" \
   | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null 
sudo apt update -y
sudo apt install -y docker-ce docker-ce-cli containerd.io 

echo "Adding current user to Docker group..."
sudo usermod -aG docker $USER 

echo "All dependencies install successfully!"
echo "Please log out and log back in to user Docker without sudo." 

Why this is production-ready 
- set -euo pipefail ensures script fails fast if anything goes wrong.
- Install specific, stable versions from trusted sources.
- Works on Ubuntu/Debain servers commonly used in production.
- Can be used in CI/CD or first-time server provisioning.

In real-world projects, this script is often:
- Stored in scripts/install_deps.sh in the repo.
- Called automatically from GitHub Actions/Jenkins before build.
- Reused across staging and production servers for consistency. 




