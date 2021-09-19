FROM alpine:3.12

RUN apk update
RUN apk add --no-cache mysql mysql-client

# Create new user
RUN adduser -D 'gandalf' -g mysql

# mysql config
COPY srcs/my.cnf /etc/
COPY srcs/start.sh .
VOLUME /var/lib/mysql

EXPOSE 3306

CMD	sh start.sh
