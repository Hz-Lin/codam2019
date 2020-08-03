#!/bin/bash
if [ $1 == "off" ]
then
	sed -i '/autoindex/c autoindex off;' /nginx/sites-available/catanmap
elif [ $1 == "on" ]
then
	sed -i '/autoindex/c autoindex on;' /nginx/sites-available/catanmap
else
	echo "Incorrect use of script, use on or off"
fi
service nginx reload