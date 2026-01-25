# Eliminating Ambiguity from the ``dangling-else`` Grammar

### Ambiguous grammar
```
stmt -> if expr then stmt
        | if expr then stmt else stmt
        | other
```
### Unambiguous grammar
```
stmt -> matched_stmt
        | open_stmt

matched_stmt -> if expr then matched_stmt else matched_stmt
                | other

open_stmt -> if expr then stmt
             | if expr then matched_stmt else open_stmt
```         
## ``stmt.l``
```
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
```
## ``stmt.y``
```
%token ADD MUL NUM SUB DIV THEN SEM IF ELSE LPAR RPAR LBRACE RBRACE
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern char *yytext;
%}
%start S

%%

S:		MS {printf("rule used: S -> MS\n");}
		| OS {printf("rule used: S -> OS\n");}
		;

MS: 	IF E THEN MS ELSE MS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: MS -> if E then MS else MS\n");}
		| SEM {$$=1;printf("rule used: MS -> ;\n");}
		| SEM MS {$$=1;printf("rule used: MS -> MS ;\n");}
		| LBRACE MS RBRACE {printf("rule used: MS -> { MS }\n");}
		;
		
OS:		IF E THEN S {$$=($2!=0)?$4:0;$$*=$2;printf("rule used: OS -> if E then S\n");}
		| IF E THEN MS ELSE OS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: OS -> if E then MS else OS\n");}
		| LBRACE OS RBRACE {printf("rule used: OS -> { OS }\n");}
		;
	
		
E:		E ADD T {$$=$1+$3;printf("rule used: E -> E + T\n");}
		| E SUB T {$$=$1-$3;printf("rule used: E -> E - T\n");}
  		| T {$$=$1;printf("rule used: E -> T\n");}
		;

T:		T MUL F {$$=$1*$3;printf("rule used: T -> T * F\n");}
		| T DIV F {$$=$1/$3;printf("rule used: T -> T / F\n");}
  		| F {$$=$1;printf("rule used: T -> F\n");}	
  		;

F:		LPAR E RPAR {$$=$2;printf("rule used: F -> ( E )\n");}		
		| NUM {$$=atoi(yytext); printf("rule used: F -> num\n");}
		;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
    return 0;
}
```
## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/lec6ex1$ ./stmt 
if (6+6*7) then if (1+4*5) then ; else ;
rule used: F -> num
rule used: T -> F
rule used: E -> T
rule used: F -> num
rule used: T -> F
rule used: F -> num
rule used: T -> T * F
rule used: E -> E + T
rule used: F -> ( E )
rule used: T -> F
rule used: E -> T
rule used: F -> num
rule used: T -> F
rule used: E -> T
rule used: F -> num
rule used: T -> F
rule used: F -> num
rule used: T -> T * F
rule used: E -> E + T
rule used: F -> ( E )
rule used: T -> F
rule used: E -> T
rule used: MS -> ;
rule used: MS -> ;
rule used: MS -> if E then MS else MS
rule used: S -> MS
rule used: OS -> if E then S
rule used: S -> OS
```
## Command-line (test case #2)
```
shouvick@shouvick:~/CS-327-Compilers/lec6ex1$ ./stmt 
if 4 then
rule used: F -> num
rule used: T -> F
rule used: E -> T
{
	if 5 {{{{;;;;}}}} else {;}
rule used: F -> num
rule used: T -> F
rule used: E -> T
syntax error
```
## Command-line (test case #3)
```
if 4 then
rule used: F -> num
rule used: T -> F
rule used: E -> T
{
	if 5 then {{{{;;;;}}}} else {;}
rule used: F -> num
rule used: T -> F
rule used: E -> T
rule used: MS -> ;
rule used: MS -> MS ;
rule used: MS -> MS ;
rule used: MS -> MS ;
rule used: MS -> { MS }
rule used: MS -> { MS }
rule used: MS -> { MS }
rule used: MS -> { MS }
rule used: MS -> ;
rule used: MS -> { MS }
rule used: MS -> if E then MS else MS
}
rule used: MS -> { MS }
rule used: S -> MS
rule used: OS -> if E then S
rule used: S -> OS
```
