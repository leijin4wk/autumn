//
// Created by Administrator on 2020/8/12.
//

#ifndef AUTUMN_CELL_H
#define AUTUMN_CELL_H
#include "page.h"


//          format:
//    char type; //INTEGER =0 TEXT=1  REAL=2  DATE=3*/
//    short table_name_size;
//    char* column_name;


struct g_table_column{
    char type; //INTEGER =0 TEXT=1  REAL=2  DATE=3*/
    char* column_name;
    struct g_table_column *next;
};

//          format:
//    char type;
//    short name_size;
//    char *name;
//    short table_name_size;
//    char *table_name;
//    char column_num;
//    short table_column_size;
//    char *table_column;
//    int root_page;
//    short sql_size;
//    char *sql;
//    char *key_name;
//    short key_name_size;
//


struct g_table_record{
    char type;
    char *name;
    char *table_name;
    struct g_table_column *list;
    int root_page;
    char *key_name;
    char *sql;
    struct g_table_record *next;
};

//##############################
struct g_cell_key{
    short key_size; //关键字大小
    char key_type; //关键字类型
    char *key; //关键字
};
struct g_cell_column{
    short  column_size; //字段大小
};

//存储结构
struct g_cell{
    short payload_size; // 纪录大小
    short key_size; //关键字大小
    char key_type; //关键字类型
    char* key; //关键字
    short head_size; // 头大小
    char* head;//记录头（字段大小）
    char* data;//数据字段
};


#endif //AUTUMN_G_CELL_H
