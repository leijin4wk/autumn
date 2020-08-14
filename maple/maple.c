//
// Created by leijin on 2020/8/3.
//
#include <stdio.h>
#include "yacc.h"
#include "maple.h"
typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string ( const char *yy_str  );
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
//#####################定义外界方法

//#####################
struct statement*  m_parser(const char * text){
    YY_BUFFER_STATE buffer = yy_scan_string(text);
    yyparse();
    yy_delete_buffer(buffer);
    return NULL;
}

void create_table(char *table_name,struct field_items_define *items,char *key_name){
    printf("table_name: %s \n",table_name);
    while (items!=NULL){
        printf("field_name: %s \n",items->field);
        printf("field_type: %d \n",items->type);
        items=items->next;
    }
    printf("key_name:%s \n",key_name);
}