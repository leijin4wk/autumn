//
// Created by Administrator on 2020/8/12.
//

#ifndef AUTUMN_G_LIST_H
#define AUTUMN_G_LIST_H
#include "g_page.h"

//  format
//    char type; //INTEGER =0 TEXT=1  REAL=2  DATE=3*/
//    short table_name_size;
//    char* column_name;


struct g_table_column{
    char type; //INTEGER =0 TEXT=1  REAL=2  DATE=3*/
    char* column_name;
    struct g_table_column *next;
};


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
    struct g_table_column *list
    int root_page;
    char *key_name;
    char *sql;
    struct g_table_record *next;
};
int get_table_record(const char * buffer,struct g_page_head *page_head,struct g_table_record * out_head);


#endif //AUTUMN_G_LIST_H
