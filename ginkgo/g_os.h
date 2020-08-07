//
// Created by leijin on 2020/8/6.
//

#ifndef AUTUMN_G_OS_H
#define AUTUMN_G_OS_H

#include <sys/types.h>

int open_file(char * name);

int close_file(int fb);

void read_page(int fd,off_t num,void *buf,size_t size);

void write_page(int fd,off_t page_num,void *buf,size_t size);

#endif //AUTUMN_G_OS_H
