%{
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include "yacc.h"
%}

%%
CREATE |
create  { return CREATE; }
TABLE |
table     { return TABLE; }
PRIMARY |
primary  {  return PRIMARY; }
KEY |
key  {  return KEY; }
INTEGER |
integer {   return INTEGER; }
VARCHAR |
varchar  {  return VARCHAR; }
REAL |
real {  return REAL; }
DATE |
date  {  return DATE; }
[\'][A-Za-z][A-Za-z0-9_]*[\'] 		{  yylval.strval=strdup(yytext); return STRING; }
[A-Za-z][A-Za-z0-9_]*	 {  yylval.strval=strdup(yytext); return ID; }
[0-9]+ 		 {  yylval.intval=atoi(yytext); return NUMBER;	}
[,]		 return *yytext;
[;]		 return *yytext;
[(] |
[)]   return *yytext;
\n						return *yytext;
[ \t]+					/* ignore whitespace */

%%