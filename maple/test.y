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
  	struct field_items_define *field_items;
}

%token CREATE TABLE PRIMARY KEY INTEGER VARCHAR REAL DATE
%token <intval> NUMBER
%token <strval> ID STRING
%type <field_items> field_items define_item
%%
statements: statements statement | statement

statement: createsql | insertsql

createsql:  CREATE TABLE ID '(' field_items ',' PRIMARY KEY  '(' ID ')' ')' ';'{
			printf("createTable\n");
			createTable($3, $5, $10);
           	}
field_items: 	define_item {
			printf("11\n");
			$$ = $1;
		}
		| field_items ',' define_item {
			printf("22\n");
			$$ = $3;
			$$->next = $1;
		}
define_item:	ID INTEGER  {
		    printf("33\n");
		    $$ = (struct field_items_define *)malloc(sizeof(struct field_items_define));
                    $$->field = $1;
                    $$->type = 0;
                    $$->size = 4;
                    $$->next = NULL;
		}
		| ID VARCHAR '(' NUMBER ')'{
		   printf("44\n");
		    $$ = (struct field_items_define *)malloc(sizeof(struct field_items_define));
                    $$->field = $1;
                    $$->type = 1;
                    $$->size = 4;
                    $$->next = NULL;
		}
		| ID REAL {
			   printf("55\n");
		    $$ = (struct field_items_define *)malloc(sizeof(struct field_items_define));
		    $$->field = $1;
		    $$->type = 2;
		    $$->size = 4;
		    $$->next = NULL;
                }
                | ID DATE {
                    printf("66\n");
		    $$ = (struct field_items_define *)malloc(sizeof(struct field_items_define));
		    $$->field = $1;
		    $$->type = 3;
		    $$->size = 4;
		    $$->next = NULL;
                }
insertsql:	INSERT INTO ID VALUES '(' value_list ')' ';'{
			printf("\n");
			multiInsert($3, NULL, $6);
			printf("\nSQL>");
		}

		|INSERT INTO ID '(' column_list ')' VALUES '(' value_list ')' ';'{
			printf("\n");
			multiInsert($3, $5, $9);
			printf("\nSQL>");
		}
column_list: 	column {
			$$ = $1;
		}
		| column_list ',' column{
			$$ = $3;
			$$->next = $1;
		}
column: 	ID {
			$$ = (struct item_def *)malloc(sizeof(struct item_def));
			$$->field = $1;
			$$->pos = NULL;
			$$->next = NULL;
		}
value_list:	value {
			$$ = $1;
		}
		| value_list ',' value {
			$$ = $3;
			$$->next = $1;
		}
value:		NUMBER {
			$$ = ((struct value_def *)malloc(sizeof(struct value_def)));
			$$->value.intkey = $1;
			$$->type = 0;
			$$->next = NULL;
		}
		| STRING {
			$$ = ((struct value_def *)malloc(sizeof(struct value_def)));
			strcpy($$->value.skey, $1);
			$$->type = 1;
			$$->next = NULL;
		}

%%
