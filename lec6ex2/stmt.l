%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

"if"		{return IF;}
"then" 		{return THEN;}
"else"  	{return ELSE;}
"+"			{return ADD;}
"-" 		{return SUB;}
"*" 		{return MUL;}
"/" 		{return DIV;}
";"			{return SEM;}
"(" 		{return LPAR;}
")" 		{return RPAR;}
"{"			{return LBRACE;}
"}"			{return RBRACE;}
[0-9]+	{strcpy(mytext, yytext); return NUM;}
.|\n			{;}

%%

int yywrap(void) {
    return 1;
}


