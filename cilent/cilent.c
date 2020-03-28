/*************************************************************************
	> File Name: cilent.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 14时52分34秒
 ************************************************************************/

#include"head.h"
#include"tcp_cilent.h"

int main(int argc,char **argv) {
    int sockfd;
    if(argc != 3) {
        fprintf(stderr,"Usage:%s ip port\n",argv[0]);
        return 1;
    }

    if((sockfd = socket_connect(argv)))
}

