//
// Created by leijin on 2020/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "g_os.h"
#include "ginkgo.h"

void g_hello(){
    char buf[PAGE_SIZE];
    struct g_page *page= malloc(sizeof(struct g_page));
    page->type=1;
    page->page_num=0;
    page->block=0;
    page->cells=0;
    page->next=-1;
    memmove(buf,page,sizeof(struct g_page));
    int fd=open_file("aa");
    write_page(fd,0,buf);
    close_file(fd);
    printf("ginkgo\n");
}