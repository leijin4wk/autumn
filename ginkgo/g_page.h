//
// Created by leijin on 2020/8/7.
//

#ifndef AUTUMN_G_PAGE_H
#define AUTUMN_G_PAGE_H

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

#endif //AUTUMN_G_PAGE_H
