#!/bin/sh

# set colors
RESET='\033[0m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'

# ---------------------------------------------------------	#
# 						INICIAL SET UP						#
# -----------------------------------------	---------------	#

# Start cluster
echo "\n$YELLOW Creating minikube cluster\n$RESET" 
minikube start --driver=virtualbox --disk-size=10GB --extra-config=kubelet.authentication-token-webhook=true

# Enable addons
echo "\n$YELLOW Installing minikube addons\n$RESET" 
minikube addons enable metallb
minikube addons enable metrics-server
minikube addons enable dashboard

# Set up environment to use minikube's Docker daemon
eval $(minikube docker-env)
echo "\n$BLUE Minikube cluster initiation completed\n$RESET"


# ---------------------------------------------------------	#
# 					BUILDING METALLLB 						#
# -----------------------------------------	---------------	#

echo "\n$YELLOW Setting up MetalLB and secrets$RESET\n"
# creating secret
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"
kubectl apply -f srcs/metallb.yaml
kubectl apply -f srcs/secrets.yaml


# ---------------------------------------------------------	#
# 					SERVICES DEPLOYMENTS					#
# -----------------------------------------	---------------	#

# Ngnix
echo "\n$YELLOW Setting up NGINX\n$RESET"
docker build -t my_nginx srcs/nginx
kubectl apply -f srcs/nginx/nginx.yaml

# MySQL
echo "\n$YELLOW Setting up MYSQL\n$RESET"
docker build -t my_mysql srcs/mysql
kubectl apply -f srcs/mysql/mysql.yaml

# PhpMyAdmin
echo "\n$YELLOW Setting up PHPMYADMIN\n$RESET"
docker build -t my_phpmyadmin srcs/phpmyadmin
kubectl apply -f srcs/phpmyadmin/phpmyadmin.yaml

# InfluxDB
echo "\n$YELLOW Setting up INFLUXDB & TELEGRAF\n$RESET"
docker build -t my_influxdb srcs/influxdb
kubectl apply -f srcs/influxdb/influxdb.yaml
docker build -t my_telegraf srcs/telegraf
kubectl apply -f srcs/telegraf/telegraf.yaml

# WordPress
echo "\n$YELLOW Setting up WORDPRESS\n$RESET"
docker build -t my_wordpress srcs/wordpress
kubectl apply -f srcs/wordpress/wordpress.yaml

# grafana
echo "\n$YELLOW Setting up GRAFANA\n$RESET"
docker build -t my_grafana srcs/grafana
kubectl apply -f srcs/grafana/grafana.yaml

# ftps
echo "\n$YELLOW Setting up FTPS\n$RESET"
docker build -t my_ftps srcs/ftps
kubectl apply -f srcs/ftps/ftps.yaml

echo "\n$BLUE Deployments completed\n$RESET"


# ---------------------------------------------------------	#
# 						DISPLAY DASHBOARD					#
# ---------------------------------------------------------	#

echo "\n$YELLOW Starting K8s Dashboard\n$RESET"
minikube dashboard

# ---------------------------------------------------------	#
# 						LOGIN INFO   						#
# ---------------------------------------------------------	#

# --- For phpmyadmin, worpress, mysql -- 
# user: gandalf
# password: include in secrets (encrypted)

# --- For grafana -- 
# user: admin
# password: include in secrets (encrypted)

# encrytion was created by using:
# echo -n "admin" | base64
# to decode: 
# echo `echo YWRtaW4= | base64 --decode`

# http://192.168.99.33:80 --> Nginx
# http://192.168.99.33:5050 --> Wordpress
# http://192.168.99.33:5000 --> PhpMyadmin
# http://192.168.99.33:3000 --> Grafana

# to add new Panels in Grafana Dashboard, you can add query as
# SELECT "created"/1000000 FROM "kubernetes_service" GROUP BY "service_name"