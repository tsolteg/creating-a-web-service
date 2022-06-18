# What is docker?
Docker is a software framework for constructing, executing, and managing containers on servers and in the cloud. It is a subset of the Moby project. The tools (commands and a daemon) or the Dockerfile file format are both referred to as "docker."
# creating-a-web-service
Hello humans, we are students from IIUM (International Islamic University Malaysia) on a project to deploy a complete Apache/NGINX, PHP, MONGODB/MYSQL and PHPMYADMIN to create a web service.  In this repo we will provide you on:
1. How to Install docker on your computer
2. How to deploy PHP on docker
3. How to deploy Apache on docker
4. How to deploy MySQL on docker
5. How to deploy PHPMyAdmin on docker

## How to Install docker on your computer 

1. Go to www.docker.com
2. Download Docker Desktop
3. Select the right version for your desktop
    - For Windows, make sure you enable Hyper-V and Container Windows
4. Install the application
5. Run the application
6. Check whether the Docker is running on your desktop or not, on Command Prompt for Windows and Terminal for MacOS
```
  docker version
```
- This indicates that the Docker is currently running on your desktop
    
![docker version](https://user-images.githubusercontent.com/83501001/174430912-cd24d7f5-bd89-422f-8238-c384ea05ea87.png)
    
7. And you are done installing Docker on your desktop!
    
## How to deploy PHP on docker

## How to deploy Apache on docker
    
## How to deploy MySQL on docker
In order to run MySQL on docker we need to :
    
1. Make sure that the Docker is running on your desktop
2. Open Cmd or Terminal depending on your OS and Log in to Docker
```
docker login
```
- You may create an account on Docker Hub https://hub.docker.com

3. Download MySQL image
- You can actually start downlading by pulling MySQL image first OR just straight run the MySQL image, if the image is not available yet, it will be downloaded first
- To pull the MySQL image, you may get the URL of the image at https://hub.docker.com/_/mysql which is 
```
  docker pull mysql
```
- After pulling the image you may run the image with your choice of instances, here we provided 2 of the instances: 

**Original MySQL instance given on Docker Hub website**
```
  docker run –name some -mysql -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql:tag
```
>some-mysql 
- is the name of the image and can be changed
>-e
- is the environment variables
>my-secret-pw
- is the example root password that can be changed  
> -d
- is the detached mode, means container runs in the background and we can use our Cmd/Terminal for other commands
- Final part is the path to image on Docker Hub which will be downloaded 
> tag
- is the version that can be downloaded, for more versions you may visit https://hub.docker.com/_/mysql

**Modified MySQL instance that we are going to use on this tutorial**
```
  docker run --name some-mysql -p 3306:3306 -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql
```
- tag removed will download the latest version of MySQL
> -p
- shorts for "port"
> 3306:3306
- will expose or open port from Docker container to our operating system, allowing us to use a program such as MySQL workbench to connect to all the databases
- If we do not expose the port, we will have to run commands on Cmd/Terminal to run SQL which is not ideal
- Run either instances and it will start downloading and take a few minutes
4. Once the image has been dowloanded, you can check the status of the container using ```docker ps ```

**"healthy" or "up 10 seconds" means the container is running***
![docker status](https://user-images.githubusercontent.com/83501001/174443499-ff3290d2-a66b-4e95-84e4-8e5f054c0a89.png)


## How to deploy PHPMyAdmin on docker

## Banker's Algorithm Program
To compile and run BankersAlgo, use Dev C++ or any other suitable C++ compiler (however this has not been tested). Compiling the .cpp file is recommended as using the .exe file has problems reading the text file.
