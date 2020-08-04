%{
#include <stdio.h>
#include <string.h>
#include "maple.h"
extern int yyparse ();
extern int yylex ();
void yyerror(const char *str)
{
   printf("error: %s\n",str);
}
int yywrap()
{
  return 1;
}
%}
%union{
	int intval;
  	char *strval;
}

%token EQ
%token <intval> AGE
%token <strval> NAME
%%
records: records  record | record ;

record:NAME EQ AGE
        {
          temp=$1;
         //注意数据类型
     	   printf("%s is %d \n", $1, $3);
     	};
%%
