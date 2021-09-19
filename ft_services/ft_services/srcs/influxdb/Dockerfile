FROM alpine:3.12

RUN apk update
RUN apk add --no-cache wget influxdb 

COPY srcs/start.sh .

EXPOSE 8086

CMD sh start.sh