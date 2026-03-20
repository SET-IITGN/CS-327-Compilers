%{
	#include <stdlib.h>
	#include "y.tab.h"
%}

%%

"+"		  			{return ADD;}
"*"		  			{return MUL;}
"("		  			{return LPAR;}
")"		  			{return RPAR;}
([0-9]+|[a-zA-Z]+)	{yylval=atoi(yytext);return NUM;}
.|\n	  			{;}

%%

int yywrap(void) {
    return 1;
}


