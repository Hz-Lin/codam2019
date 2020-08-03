#!/bin/bash
if [ $1 == "off" ]
then
	sed -i '/autoindex/c autoindex off;' /etc//nginx/sites-available/server.conf
elif [ $1 == "on" ]
then
	sed -i '/autoindex/c autoindex on;' /etc//nginx/sites-available/server.conf
else
	echo "Incorrect use of script, use on or off"
fi
service nginx reload