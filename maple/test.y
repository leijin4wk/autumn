%{
#include <stdio.h>
#include <stdlib.h>
typedef char* string;
#define YYSTYPE string
%}
%token NAME EQ AGE

%%
file : record file
    | record
;
record : NAME EQ AGE {
                printf("%s is %s years old!!!\n", $1, $3); }
;
%%

int yyerror(char *msg)
{
    printf("Error encountered: %s \n", msg);
}