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
4. Download MySQL image
```
  docker run --name some-mysql -p 3306:3306 -e MYSQL_ROOT_PASSWORD=my-secret-pw -d mysql
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
    

## How to deploy PHPMyAdmin on docker

