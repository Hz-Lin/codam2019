# base image, the OS runing in the container
FROM debian:buster

# expose port 80 for HTTP, 443 for HTTPS
EXPOSE 80 443

# update the system
RUN apt-get update && apt-get upgrade -y
# install pakages
RUN apt-get install -y \
	mariadb-server \
	sendmail \
	nginx \
	php-fpm php-mysql php-cli php-mbstring

# catanmap website
WORKDIR /var/www/catanmap/
COPY /srcs/catanmap/index.html .
COPY /srcs/catanmap/style.css .
COPY /srcs/catanmap/main.js .

# nginx configure
COPY /srcs/nginx.config /etc/nginx/sites-available/catanmap
COPY /srcs/server.key /etc/nginx/ssl/server.key
COPY /srcs/server.pem /etc/nginx/ssl/server.pem
RUN ln -s -f /etc/nginx/sites-available/catanmap /etc/nginx/sites-enabled/catanmap && nginx -t
# add autoindex script
COPY /srcs/autoindex.sh .
RUN chmod +x autoindex.sh

# phpmyadmin install and configure
COPY /srcs/phpMyAdmin-5.0.2-english.tar.gz .
RUN tar xf phpMyAdmin-5.0.2-english.tar.gz && rm phpMyAdmin-5.0.2-english.tar.gz
RUN mv phpMyAdmin-5.0.2-english phpmyadmin
COPY /srcs/config.inc.php phpmyadmin
COPY /srcs/php.ini /etc/php/7.3/fpm/
COPY srcs/phpMyAdmin.conf /etc/nginx/conf.d/

# create the mysql database
RUN	 service mysql start \
&& echo "CREATE DATABASE catanmap_db;" | mysql -u root \
&& echo "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'localhost' IDENTIFIED BY 'password';" | mysql -u root \
&& echo "CREATE DATABASE phpmyadmin" | mysql -u root \
&& echo "FLUSH PRIVILEGES" | mysql -u root \
&& mysql phpmyadmin < /var/www/catanmap/phpmyadmin/sql/create_tables.sql

# wordpress install and configure
COPY /srcs/wordpress-5.4.2.tar.gz .
RUN tar xf wordpress-5.4.2.tar.gz && rm wordpress-5.4.2.tar.gz
COPY /srcs/wp-cli.phar .
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN wp cli update
WORKDIR /var/www/catanmap/wordpress
RUN	service mysql start \
&& wp config create --allow-root --dbhost=localhost --dbname=catanmap_db --dbuser=admin --dbpass=password \
&& wp core install --allow-root --url=https://localhost/wordpress --title="wordpress" --admin_name=admin --admin_password=password --admin_email=hlin@student.codam.nl
RUN chmod 644 wp-config.php

# change the user privileges
RUN chown -R www-data:www-data /var/www/catanmap/*
RUN chmod 755 -R /var/www/catanmap/*

# increase the max upload and post size in the php.ini
RUN sed -i '/upload_max_filesize/c upload_max_filesize = 20M' /etc/php/7.3/fpm/php.ini
RUN sed -i '/post_max_size/c post_max_size = 20M' /etc/php/7.3/fpm/php.ini

# start all the services whem starting this image
CMD service nginx restart && \
	service php7.3-fpm start && \
	service mysql start && \
	echo "$(hostname -i) $(hostname) $(hostname).localhost" >> /etc/hosts && \
	service sendmail start && \
	bash