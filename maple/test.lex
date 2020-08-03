%{
  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include "yacc.h"
%}

%%
[A-Za-z]+        {yylval.strval=strdup(yytext); return NAME;}
[=]              {return EQ; }
[0-9]+           {yylval.intval=atoi(yytext); return AGE;}
[ \t]+                  /* ignore whitespace */;

%%