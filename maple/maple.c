//
// Created by leijin on 2020/8/3.
//
#include <stdio.h>
#include "yacc.h"
#include "maple.h"
typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string ( const char *yy_str  );
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);

struct statement*  m_parser(const char * text){
    YY_BUFFER_STATE buffer = yy_scan_string(text);
    yyparse();
    yy_delete_buffer(buffer);
    struct statement *aa=yylval.statement_list;
    return NULL;
}