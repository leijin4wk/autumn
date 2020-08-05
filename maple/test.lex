%{
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include "yacc.h"
%}

%%
CREATE | create  { return CREATE; }

TABLE |table { return TABLE; }

INTEGER | integer { return INTEGER; }

VARCHAR | varchar  { return VARCHAR; }

CHAR  | char  { return CHAR; }

REAL | real { return REAL; }

TEXT | text { return TEXT; }

TIME | time  { return TIME; }

NOT | not   { return NOT; }

NULL | null   { return NULL; }

[\'][A-Za-z][A-Za-z0-9_]*[\'] 		{ yylval.strval=strdup(yytext); return STRING; }

[A-Za-z][A-Za-z0-9_]*	 { yylval.strval=strdup(yytext); return IDENTIFIER; }

[0-9]+ 		 { yylval.intval=atoi(yytext); return NUMBER;	}

[;]		 return *yytext;

[(] | [)]   return *yytext;

\n						return *yytext;

%%