/*************************************************************************
	> File Name: cilent.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月22日 星期日 20时34分37秒
 ************************************************************************/

#include"head.h"
int socket_connect(char host, int port) {
     int sockfd,port;
    struct sockaddr_in sever;
    sever.sin_family = AF_INET;
    sever.sin_port = htons(port);
    sever.sin_addr.s_addr = inet_addr(host);

    if((sockfd = socket(AF_INET,SOCK_STREAM,0)) < 0) {
        perror("socket");
        return -1;
    }
    printf("Socket create.\n");
    if(connect(sockfd,(struct sockaddr *)&sever,sizeof(sever)) < 0) {
        perror("connect");
        return -1;
    }

    return 0;
}
