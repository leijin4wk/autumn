%{
#include <stdio.h>
#include <stdlib.h>
typedef char* string;
#define YYSTYPE string
%}
%token NAME EQ AGE

%%
statements: statements statement
           | statement
           ;
statement: NAME EQ AGE {
                     printf("%s is %s years old!!!\n", $1, $3);
           };
%%

int yyerror(char *msg)
{
      printf("Error: %s\n", msg);
}