//
// Created by Administrator on 2020/7/28.
//
#include <stdio.h>
#include "yacc.h"
int main(int argc, char **argv) {
    extern FILE* yyin;
    if (!(yyin = fopen("test.txt", "r")))
    {
        perror("cannot open parsefile:");
        return -1;
    }

    yyparse();
    fclose(yyin);
    return 0;
}