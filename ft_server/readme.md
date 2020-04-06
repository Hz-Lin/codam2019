# ft_server

## Docker Commands

### Start a container

```bash
docker run <image-name>
```

### List containers

```bash
docker ps  
docker ps -a
```

### Stop a container

```bash
docker stop <image-name/id>
```

### Remove a container

```bash
docker rm <image-name/id>
```

### list images

```bash
docker images
```

### Remove images

```bash
docker rmi <image-name/id>
```

### Download an image

```bash
docker pull <image-name>
```

### Append a command

```bash
docker run <image-name> <command args>
docker run ubuntu sleep 5
```

### Execute a command

```bash
docker exec <container-name> <command args>
docker exec <container-name> cat /etc/host
```

### Attach & Detach

```bash
# run in background with -d
docker run -d <image-name>
# to attach the container
docker attach <name/>id>
```

## Docker Run

### tag

default tag: latest

```bash
docker run <name:tag>
docker run redis:4.0
```

### STDIN

```bash
docker run -i <container-name> <command args>
docker run -it <container-name> cat /etc/host
```

### PORT mapping

```bash
docker run -p <port-num-in-container> <port-num-on-Docker-host>
docker run -p 8080:80

docker run -p <host-ip>:<port-num-in-container> <port-num-on-Docker-host>
docker run -p 192.168.1.100:8080:80

docker run -p <port-num-in-container> <port-num-on-Docker-host>/<protocol>
docker run -p 8080:80/tcp -p 8080:80/udp
```

### Volume mapping

```bash
docker run -v <name-of-volume>:<path-of-file/>dir-mounted-on-container>:<options> 
docker run -v /opt/datadir:/var/lib/mysql
# options are optional, eg: ro, etc
```

### Inspect container

```bash
docker inspect <name/id>
```

### Container logs

```bash
docker logs <name>id>
```

### Environment variables

```bash
docker run -e <env> <image-name>
docker run -e APP_COLOR_BLUE simple_webapp_color

docker run -e <env>=<value> <image-name>
docker run -e APP_COLOR=green simple_webapp_color
docker run -e APP_COLOR=pink simple_webapp_color
```

## Docker Images

### create image

Example: create a image of a web server using flask  

1. OS - Ubuntu
2. Update apt repo
3. Install dependencies using apt
4. Install Python dependencies using pip
5. Copy source code to /opt folder
6. Run the web server using "flask" command

### Create a Dockerfile and set up the applications

Dockerfile format:  
INSTRUCTION argument

```bash
FROM Ubuntu
# start from a base OS or another image

RUN apt-get update
RUN apt-get install python

RUN pip install flask
RUN pip install flask-mysql
# install all dependencies

COPY . /opt/source-code
# copy source code

ENRTYPOINT FLASK_APP=/opt/source-code/app/py flask run
# specify entrypoint
```

#### Layered architecture4

Create the layered architecture using the Dockerfile

```bash
docker build Dockerfile -t mmunshad/my-custom-app
```

Layer 1. Base Ubuntu layer  
Layer 2. Changes in apt packages  
Layer 3. Changes in pip packages  
Layer 4. Source code  
Layer 5. Update Entrypoint with "flask" command

Build is cashed, in case of failure or add more layers, cashes are used to improve the rebulid speed.

#### Push the image

```bash
Docker push mmunshad/my-custom-app
```

### Command & Entrypoint

#### CMD

In docker file, to define a default command

```bash
# for example
CMD ["nginx"]
CMD ["mysql"]
CMD ["bash"]
```

To create your own command

```bash
CMD command param 1
CMD ["command","param 1"]
# for example
CMD sleep 5
CMD ["sleep","5"]
```

#### Entrypoint

To make the parameter of command not hard coded

```bash
# name the image ubuntu-sleeper, then in Dockerfile
FROM Ubuntu

ENTRYPOINT ["sleep"]

# in console run 
docker run ubuntu-sleeper 10
#command at startup became: sleep 10
```

#### Use them together

```bash
# in Dockerfile
FROM Ubuntu

ENTRYPOINT ["sleep"]

CMD ["5"]
```

Command at Startup: sleep 5; if not specify any parameter in console  
If specify a parameter in console, the specified parameter will overwrite the default

### Docker Compose


