docker run -itd --name hjs -v "C:/Users/user/Desktop/shared file:/home/share" --restart=always hjtn/ubuntu:20.04
docker exec -it hjs /bin/bash
docker attach hjs
