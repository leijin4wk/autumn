//
// Created by Administrator on 2020/7/28.
//
#include <stdio.h>
#include "yacc.h"
typedef struct yy_buffer_state * YY_BUFFER_STATE;
extern YY_BUFFER_STATE yy_scan_string ( const char *yy_str  );
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
int main(int argc, char **argv) {
    char string[] = "aa=1bb=2cc=33";
    YY_BUFFER_STATE buffer = yy_scan_string(string);
    yyparse();
    yy_delete_buffer(buffer);
    return 0;
}