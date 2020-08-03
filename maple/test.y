%{
#include <stdio.h>
#include <string.h>

extern int yyparse ();

extern int yylex ();

void yyerror(const char *str)
{
  fprintf(stderr,"error: %s\n",str);
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
           printf("%s \n", $1);
           printf("%d \n", $3);
     	   printf("%s is %d years old!!!\n", $1, $3);
     	};
%%
