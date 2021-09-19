FROM alpine:3.12

RUN apk update
RUN apk add --no-cache wget

# Updating telegraf version
ENV TELEGRAF_VERSION 1.17.2

# Downloading telegraf agent
RUN wget -nv https://dl.influxdata.com/telegraf/releases/telegraf-${TELEGRAF_VERSION}_static_linux_amd64.tar.gz && \
    tar -xf telegraf-${TELEGRAF_VERSION}_static_linux_amd64.tar.gz --strip-components=2 -C . && \
	rm telegraf-${TELEGRAF_VERSION}_static_linux_amd64.tar.gz

COPY srcs/telegraf.conf /etc/telegraf/
COPY srcs/start.sh .

CMD sh start.sh