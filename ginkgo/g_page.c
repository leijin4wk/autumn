//
// Created by Administrator on 2020/8/16.
//
#include "g_page.h"
#include "g_util.h"
#include "stdlib.h"
#include <string.h>
/**
 * 获取缓冲中的头字段
 * @param buffer
 * @return 返回 页面的类型
 */
int get_page_head(const char * buffer,struct g_page_head * out_head){
    //获取页面类型
    out_head->type=*buffer;
    out_head->free_black_offset=*((short*)(buffer+1));
    out_head->cells=*((short*)(buffer+3));;
    out_head->first_content=*((short*)(buffer+5));;
    out_head->fragment=*(buffer+7);
    if (out_head->type==1){
        out_head->right_page_number=*((int*)(buffer+8));
    }else{
        out_head->right_page_number=0;
    }
    return 1;
}

/**
 * 获取页面记录相关数组
 * @param buffer
 * @param out_head
 * @param head
 * @return
 */
int get_cell_list(const char * buffer,const struct g_page_head * page_head,struct g_cell_item **head){

}


/**
 *  创建一个新的页面
 * @param type
 * @param out_buffer
 * @return
 */
int new_page(char type,char ** out_buffer,struct g_page_head * out_head,int page_number){
    out_head->type=type;
    memcpy(*out_buffer,&out_head->type,1);
    out_head->free_black_offset=-1;
    memcpy(*out_buffer+1,&out_head->free_black_offset,2);
    out_head->cells=0;
    memcpy(*out_buffer+3,&out_head->cells,2);
    out_head->first_content=PAGE_SIZE;
    memcpy(*out_buffer+5,&out_head->first_content,2);
    out_head->fragment=0;
    memcpy(*out_buffer+7,&out_head->fragment,1);
    if (type==1){
        out_head->right_page_number=page_number;
        memcpy(*out_buffer+8,&out_head->right_page_number,4);
    }else{
        out_head->right_page_number=0;
    }
    return 1;
}