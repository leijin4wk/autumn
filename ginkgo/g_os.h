//
// Created by leijin on 2020/8/6.
//

#ifndef AUTUMN_G_OS_H
#define AUTUMN_G_OS_H

#include <sys/types.h>
/**
 * 定义页面结构
 */
struct g_page{
    char type; //定义也面类型
    long page_num;//页面编号
    short block; //空闲位置
    off_t cells;//页面记录数
    off_t next; //下一个页面位置
};

int open_file(char * name);

int close_file(int fb);

void read_page(int fd,int page_num,void *buf);

void write_page(int fd,int page_num,void *buf);

#endif //AUTUMN_G_OS_H
