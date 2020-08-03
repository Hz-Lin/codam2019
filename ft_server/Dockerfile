# base image, the OS runing in the container
FROM debian:buster

# expose port 80 for HTTP, 443 for HTTPS
EXPOSE 80 443

# update the system
RUN apt-get update && apt-get upgrade -y
# install pakages
RUN apt-get install -y \
	sudo openssl \
	mariadb-server \
	sendmail \
	nginx \
	php-fpm php-mysql php-cli php-mbstring

WORKDIR /var/www/html/

# phpmyadmin install and configure
RUN mkdir -p /var/www/html/wordpress
WORKDIR  /var/www/html/wordpress
COPY /srcs/phpMyAdmin-5.0.2-english.tar.gz .
RUN tar xf phpMyAdmin-5.0.2-english.tar.gz && rm phpMyAdmin-5.0.2-english.tar.gz
RUN mv phpMyAdmin-5.0.2-english phpmyadmin
COPY /srcs/config.inc.php phpmyadmin

# create the mysql database for wordpress
RUN	 service mysql start \
&& mysql -e "CREATE DATABASE wordpress_db;" \
&& mysql -e "CREATE USER 'admin'@'localhost' IDENTIFIED BY 'password';" \
&& mysql -e "GRANT ALL PRIVILEGES ON *.* TO 'admin'@'localhost' WITH GRANT OPTION;" \
&& mysql -e "FLUSH PRIVILEGES;"

# copy the wordpress-cli files and update it
COPY /srcs/wp-cli.phar .
RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp
RUN wp cli update

# add the super-user admin
RUN adduser --disabled-password --gecos "" admin
RUN sudo adduser admin sudo

# configure wordpress cli
# add all the data of the database to the phpmyadmin congfig
RUN	service mysql start && sudo -u admin -i wp core download \
&& mysql < /var/www/html/wordpress/phpmyadmin/sql/create_tables.sql \
&& sudo -u admin -i wp config create --dbhost=localhost --dbname=wordpress_db --dbuser=admin --dbpass=password \
&& sudo -u admin -i wp core install --allow-root --url=https://localhost/ --title="wordpress" --admin_name=admin --admin_password=password --admin_email=hlin@student.codam.nl
RUN cp -r /home/admin/. /var/www/html/wordpress
RUN chown -R www-data:www-data /var/www/html/*

# nginx configure
COPY /srcs/server.config /etc/nginx/sites-available/server.conf
# add the certificate
COPY /srcs/server.key /etc/nginx/ssl/server.key
COPY /srcs/server.pem /etc/nginx/ssl/server.pem
RUN ln -s -f /etc/nginx/sites-available/server.conf /etc/nginx/sites-enabled/server.conf && nginx -t
RUN rm -rf /etc/nginx/sites-enabled/default
# add autoindex script
WORKDIR /var/www/html/
COPY /srcs/autoindex.sh .
RUN chmod +x autoindex.sh

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