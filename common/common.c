/*************************************************************************
	> File Name: common.c
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 20时21分27秒
 ************************************************************************/

#include "head.h"
#include "common.h"
void make_noblock_iocntl(int fd) {
    unsigned long ul = 1;
    ioctl(fd,FIONBIO,&ul);
}
void make_block_iocntl(int fd) {
    unsigned long ul = 0;
    ioctl(fd,FIONBIO,&ul);
}
void make_nonblock(int fd) {
    int flag;
    if (flag = fcntl (fd, F_GETFL, 0) < 0) {
        perror("fcntl");
        return ;
    }

    flag |= O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flag) < 0) {
        perror("fcntl");
        return ;
    }
}

void make_block(int fd) {
    int flag;
    if (flag = fcntl (fd, F_GETFL, 0) < 0) {
        perror("fcntl");
        return ;
    }
    flag &= ~O_NONBLOCK;
    if (fcntl(fd, F_SETFL, flag) < 0) {
        perror("fcntl");
        return ;
    }
}
