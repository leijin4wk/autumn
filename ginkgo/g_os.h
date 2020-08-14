//
// Created by leijin on 2020/8/6.
//

#ifndef AUTUMN_G_OS_H
#define AUTUMN_G_OS_H

#include <sys/types.h>

/**
 * 定义页面结构
 */
struct g_file_head{
    char type; //定义也面类型
    long page_num;//页面编号
    off_t black_offset; //空闲位置
    int cells;//页面记录数
    off_t next; //下一个页面位置
};

int open_file(char * name);

int close_file(int fb);

void read_data(int fd,off_t offset, size_t buff_size,void *buf);

void write_data(int fd,off_t offset, size_t buff_size,void *buf);

#endif //AUTUMN_G_OS_H
