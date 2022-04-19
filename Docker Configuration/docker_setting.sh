docker run -itd --name {Container name} -v "{local path}:/home/share" --restart=always {docker image}
docker exec -it {Container name} /bin/bash
docker attach {Container name}
