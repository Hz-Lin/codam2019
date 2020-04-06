#!/bin/bash                                                                                                                                                                             
if [[ $EUID -eq 0 ]]; then
   echo "This script must be run as non root user he will ask permission himself"
   exit 1
fi
if id -nG "$USER" | grep -qw "sudo"; then
    echo $USER Check OK proceed...
else
    echo $USER does not belong to sudo call to sudo may fail run as root : usermod -aG $USER sudo
    exit 1
fi
sudo apt-get install ruby gcc make ruby-dev -y
sudo /usr/bin/gem install bundler --source http://rubygems.org
sudo /usr/bin/gem install bundler --version 1.17.3 --source http://rubygems.org
sudo gem install bundler -v 2.0.2
sudo mkdir -p /opt/norminette
sudo cp -r ./src/* /opt/norminette/
sudo chmod o+rx /opt/norminette/*
sudo ln -s /opt/norminette/norminette.rb /usr/local/bin/norminette
sudo gem pristine json --version 2.2.0
cd /opt/norminette && /usr/local/bin/bundle
