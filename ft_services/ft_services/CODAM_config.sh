#! /bin/sh

# set colors
RESET='\033[0m'
PURPLE='\033[0;35m'
CYAN='\033[1;36m'

# ---------------------------------------------------------	#
# 					PRELIMINARY CHECKS 						#
# -----------------------------------------	---------------	#

# ********** CHECK FOR DOCKER DESKTOP & VM  **********
# In Manage Software Center, install VirtualBoxfrom and Docker icons

# ********** CHECK HOMEBREW **********
echo -e "\n$CYAN Checking for Homebrew version... $RESET"
command -v brew
if [ $? == 1 ]; then
	echo "I require Homebrew but it's not installed. Install and restart the terminal"
	echo "Aborting"
	exit 1
else
	echo "Brew is already installed\n"
fi
# In case is not installed, follow this link (brew without sudo)
# https://stackoverflow.com/questions/35775102/how-to-install-homebrew-packages-locally


# ********** CHECK KUBECTL **********
echo -e "\n$CYAN Checking for kubectl version... $RESET"
command -v kubectl
if [ $? == 1 ]; then
	echo "I require kubectl but it's not installed. Installing..."
	brew install kubectl
else
	echo "kubectl is already installed\n"
fi

# ********** CHECK MINIKUBE **********
echo -e "\n$CYAN Creating a link in goinfre for Minikube... $RESET"
command -v minikube
if [ $? == 1 ]; then
	echo "I require minikube but it's not installed. Installing..\n"
	brew install minikube
else
	echo "minikube is already installed\n"
fi
echo -e "\n$CYAN Creating a link in goinfre for minikube... $RESET"
rm -rf ~/.minikube
mkdir -p ~/goinfre/.minikube
ln -s ~/goinfre/.minikube ~/.minikube
echo -e "$PURPLE minikube linking completed 👍\n$RESET"

# ********** CHECK DOCKER  **********
echo -e "\n$CYAN Creating a link in goinfre for Docker... $RESET"
rm -rf ~/Library/Containers/com.docker.docker
mkdir -p ~/goinfre/docker
ln -s ~/goinfre/docker ~/Library/Containers/com.docker.docker
echo -e "$PURPLE docker linking completed 👍\n$RESET"


# ********** TEST FTPS WITHOUT FILEZILLA  **********

# ----- Install lftp ----
# brew install lftp

# ------ Run lftp ----

# 1. Go to your file location /Users/<INTRANAME>/Downloads

# 2. Type: 
# lftp ftp://gandalf@192.168.99.33 -e "set ssl:verify-certificate false"

# 3. Type your password
# password: <type your password>

# 4. use 'put' command for to transfer your files
# lftp gandalf@192.168.99.33 ~> put <your file>

# 5. use 'ls' command to list your transfered files
# lftp gandalf@192.168.99.33 ~> ls
