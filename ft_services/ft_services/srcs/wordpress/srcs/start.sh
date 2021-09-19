#!/bin/sh

cd /www/
wp db create
wp core install --url=wordpress/ --path=/www --title=Arda --admin_user=gandalf --admin_password=wizard --admin_email=gandalf@middleearth.com --skip-email
wp option update blogdescription "The Middle-Earth"
wp user create Sauron editor@lotr.com --role=editor --user_pass=editor
wp user create Frodo author@lotr.com --role=author --user_pass=author
wp user create Sam contributor@lotr.com --role=contributor --user_pass=contributor
wp user create Pippin subscriber@avlotratar.com --role=subscriber --user_pass=subscriber
wp user create Merry subscriber2@lotr.com --role=subscriber --user_pass=subscriber2

php-fpm7 & nginx -g "daemon off;"