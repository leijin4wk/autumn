%{
#include "yacc.h"
#include <stdio.h>
#include <string.h>
%}

%%
[A-Za-z]+        {yylval = strdup(yytext); printf("%s",yytext);return NAME;}
[=]              {return EQ; }
[0-9]+           {yylval = strdup(yytext); printf("%s\n",yytext); return AGE;}
[ \t]+
%%

int yywrap()
{
     return 1;
}