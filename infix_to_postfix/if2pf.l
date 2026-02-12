%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

"+"		  			{return ADD;}
"-"  	  			{return SUB;}
"*"		  			{return MUL;}
"/"		  			{return DIV;}
"("		  			{return LPAR;}
")"		  			{return RPAR;}
([0-9]+|[a-zA-Z]+)	{strcpy(yylval.buff,yytext); return NUM;}
.|\n	  			{;}

%%

int yywrap(void) {
    return 1;
}


