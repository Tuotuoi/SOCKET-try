/*************************************************************************
	> File Name: common.h
	> Author: 
	> Mail: 
	> Created Time: 2020年03月28日 星期六 20时24分26秒
 ************************************************************************/

#ifndef _COMMON_H
#define _COMMON_H
void make_noblock_ioctl(int fd);
void make_block_ioctl(int fd);
void make_noblock(int fd);
void make_block(int fd);
#endif
