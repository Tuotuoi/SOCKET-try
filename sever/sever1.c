/*************************************************************************
	> File Name: sever1.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 15时02分25秒
 ************************************************************************/

#include"head.h"
#include"tcp_sever.h"

void chstr(char *str) {
    for(int i = 0; i < strlen(str);i++) {
        if(str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
}

void *work(void *arg) {
    int *fd = (int *)arg;
    if (send(fd,"You Are Here",sizeof("You Are Here"),0) < 0){
        perror("send");
        close(fd);
        return NULL;
    }
    while (1) {
        char msg[512] = {0};
        if (recv(fd,msg,sizeof(msg),0) <= 0) {
            break;
        }
        chstr(msg);
        send(fd,msg,strlen(msg),0);

    }
    close(fd);
    return NULL;
}

int main(int argc,char **argv) {
    int port,sever_listen,fd;
    if(argc != 2) {
        fprintf(stderr,"Usage : %s port!\n",argv[0]);
        return 1;
    }
    port = atoi(argv[1]);

    if((sever_listen = socket_create(port)) < 0) {
        perror("socket_create");
        return 2;
    }

    pthread_t tid;
    while(1) {
        if((fd = accept(sever_listen,NULL,NULL)) < 0) {
            perror("accept");
        }
        pthread_create(&tid,NULL,work,(void *)&fd);
    }
}
