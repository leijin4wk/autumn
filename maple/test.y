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
  	struct statement *statement_list;
}

%token CREATE  TABLE INTEGER VARCHAR CHAR REAL TEXT TIME NOT NULL
%token <intval> AGE
%token <strval> NAME
%type <statement_list> statements statement
%%
statements: statements statement

statement: createsql  | insertsql | selectsql

createsql:

%%
