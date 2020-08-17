//
// Created by Administrator on 2020/8/12.
//

#ifndef AUTUMN_G_PAGE_H
#define AUTUMN_G_PAGE_H
#include "ginkgo.h"
enum PAGE_TYPE{
    TABLE_LEAF = 0,//table叶子节点
    TABLE_INTERIOR = 1,//table关键字节点
    INDEX_LEAF = 2,//index 叶子节点
    INDEX_INTERIOR = 3//index 关键字节点
};
/**
 * 定义页面结构
 */
struct g_page_head{
    char type; //定义页面类型  0：table叶子节点 1：table关键字节点 2:index 叶子节点，3：index 关键字节点 （1字节）
    short free_black_offset; //空闲cell(被删除的)链表头 （2字节）
    short cells;//页面记录数  （2字节）
    short first_content;   // （2字节）(这个值依赖页面的大小)
    char fragment; //纪录由于cell被重新使用而产生的碎片，用于判断页面是否要被整理 （1个字节）
                             //如果是叶子节点，这个值不存在，如果是b树，则保存最右边孩子的页数
    int right_page_number;   // （4个字节);如果是list节点，则保存下个list 页数；如果是溢出节点，则保存下个list 页数
};

struct g_cell_item{
    char *key;
    short key_size;
    short off_set;
    struct g_cell_item *next;
};
/**
 * 获取缓冲中的头字段
 * @param buffer
 * @return 返回 页面的类型
 */
int get_page_head(const char * buffer,struct g_page_head * out_head);

 /**
  * 获取页面记录相关数组
  * @param buffer
  * @param out_head
  * @param head
  * @return
  */
int get_cell_list(const char * buffer,const struct g_page_head * page_head,struct g_cell_item **head);


/**
 *  创建一个新的页面
 * @param type
 * @param out_buffer
 * @return
 */
int new_page(char type,char ** out_buffer,struct g_page_head * out_head,int page_number);


#endif //AUTUMN_G_PAGE_H
