//
// Created by Administrator on 2020/8/12.
//

#ifndef AUTUMN_G_PAGE_H
#define AUTUMN_G_PAGE_H

#include <sys/types.h>

/**
 * 定义页面结构
 */
struct g_page_head{
    char type; //定义页面类型  0：叶子节点 1：关键字节点
    short free_black_offset; //空闲cell(被删除的)链表头
    short cells;//页面记录数
    short first_content;
    char fragment; //纪录由于cell被重新使用而产生的碎片，用于判断页面是否要被整理

};

#endif //AUTUMN_G_PAGE_H
