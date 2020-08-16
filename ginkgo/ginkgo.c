//
// Created by leijin on 2020/8/3.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ginkgo.h"
#include "g_page.h"
#include "g_util.h"
void g_hello(){
    char *out_buffer=calloc(sizeof(char),PAGE_SIZE);
    struct g_page_head b;
    new_page(1, &out_buffer,&b,55);
    struct g_page_head c;
    int d=get_page_head(out_buffer,&c);
    printf("%d\n",d);
}