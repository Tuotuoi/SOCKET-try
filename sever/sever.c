/*************************************************************************
	> File Name: sever.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时04分47秒
 ************************************************************************/

#include "head.h"

void *recvive(void *arg) {
    char name[20] = {0};
    int *tmp;
    tmp = (int *)arg;
    if(recv(*tmp,name,sizeof(name),0) <= 0) {
        perror("recv");
        close(*tmp);
    }
    printf("Name = %s\n",name);
    int retval = 3;
    pthread_exit((void *)&retval);
    
}


int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr,"Usage : %s port\n",argv[0]);
        exit(1);
    }
    int port, sever_listen;
    port = atoi(argv[1]);

    if ((sever_listen = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in sever;
    sever.sin_family = AF_INET;
    sever.sin_port = htons(port);
    sever.sin_addr.s_addr = INADDR_ANY;
    if(bind(sever_listen,(struct sockaddr *)&sever,sizeof(sever)) < 0) {
        perror("bind");
        exit(1);
    }
    if(listen(sever_listen,20) < 0) {
        perror("sever");
        exit(1);
    }
    while(1) {
        int sockfd;
        if ((sockfd = accept(sever_listen,NULL,NULL)) < 0) {
            perror("accept");
            close(sockfd);
            continue;
        }

       /* pid_t pid;
        if((pid = fork()) < 0) {
            perror("fork");
            continue;
        }

        if(pid == 0) {
            close(sever_listen);
            char name[20] = {0};
            if(recv(sockfd,name,sizeof(name),0) <= 0) {
                perror("recv");
                close(sockfd);
            }
            printf("Name = %s\n",name);
            exit(0);
        }*/
        void *status;

        pthread_t tid;
        pthread_create(&tid,NULL,recvive,(void *)&sockfd);
        pthread_join(tid,&status);
        printf("%d\n",*(int*)status);
        sleep(1);

    }
    return 0;
}
