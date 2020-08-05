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

%token EQ
%token <intval> AGE
%token <strval> NAME
%type <statement_list> statements statement
%%
statements: statements statement
	{
		$$ = $2;
		$$->next = $1;
	}
	| statement
	{
  	    	$$ = $1;
	}

statement:NAME EQ AGE
        {
		printf("%s is %d \n", $1, $3);
		$$ = (struct statement *)malloc(sizeof(struct statement));
		$$->name = $1;
		$$->age = $3;
		$$->next = NULL;
     	};
%%
