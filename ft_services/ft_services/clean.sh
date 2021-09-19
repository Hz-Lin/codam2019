#! /bin/sh

# set colors
RESET='\033[0m'
YELLOW='\033[1;33m'

# ********** REMOVING K8S OBJECTS **********

echo "\n$YELLOW Deleting k8s deployments\n$RESET"
kubectl delete -f srcs/secrets.yaml
kubectl delete -f srcs/metallb.yaml
kubectl delete -f srcs/nginx/nginx.yaml
kubectl delete -f srcs/wordpress/wordpress.yaml
kubectl delete -f srcs/mysql/mysql.yaml
kubectl delete -f srcs/phpmyadmin/phpmyadmin.yaml
kubectl delete -f srcs/grafana/grafana.yaml
kubectl delete -f srcs/influxdb/influxdb.yaml
kubectl delete -f srcs/telegraf/telegraf.yaml

# ********** REMOVING DOCKER PROPERTIES  **********

echo "\n$YELLOW Deleting docker images & containers\n$RESET"
docker container prune -f
docker image prune -a --force

# ********** STOP K8S and DELETE INSTANCE  **********
echo "\n$YELLOW Deleting minikube instance\n$RESET"
minikube stop
minikube delete
