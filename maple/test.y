%{
#include <stdio.h>
#include <string.h>

extern int yyparse ();

extern int yylex ();

void yyerror(const char *str)
{
  fprintf(stderr,"\nerror: %s\n",str);
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

%token NAME EQ AGE
%token <intval> AGE
%token <strval> NAME
%%
records: records  record | record ;

record:NAME EQ AGE
        {
         //注意数据类型
     	   printf("%s is %d \n", $1, $3);
     	};
%%
