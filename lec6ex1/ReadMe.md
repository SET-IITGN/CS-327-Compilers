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
	int time;
	FILE *fp;
%}
%start Start

%%

Start: 	S {$$=$1;printf("rule used: Start -> S\n");fprintf(fp,"\"(%d) Start\" -> \"(%d) S\"",time+1,time);printf("The final output is %d\n",$$);time++;}
		;

S:		MS {$$=$1;printf("rule used: S -> MS\n");fprintf(fp,"\"(%d) S\" -> \"(%d) MS\"",time+1,time);time++;}
		| OS {$$=$1;printf("rule used: S -> OS\n");fprintf(fp,"\"(%d) S\" -> \"(%d) OS\"",time+1,time);time++;}
		;

MS: 	IF E THEN MS ELSE MS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: MS -> if E then MS else MS\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) if E then MS else MS\"",time+1,time);time++;}
		| SEM {$$=1;printf("rule used: MS -> ;\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) ;\"",time+1,time);time++;}
		| SEM MS {$$=$2;printf("rule used: MS -> ; MS\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) ; MS\"",time+1,time);time++;}
		| LBRACE MS RBRACE {$$=$2;printf("rule used: MS -> { MS }\n");fprintf(fp,"\"(%d) MS\" -> \"(%d) { MS }\"",time+1,time);time++;}
		;
		
OS:		IF E THEN S {$$=($2!=0)?$4:0;$$*=$2;printf("rule used: OS -> if E then S\n");fprintf(fp,"\"(%d) OS\" -> \"(%d) if E then S\"",time+1,time);time++;}
		| IF E THEN MS ELSE OS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: OS -> if E then MS else OS\n");fprintf(fp,"\"(%d) OS\" -> \"(%d) if E then MS else OS\"",time+1,time);time++;}
		| LBRACE OS RBRACE {$$=$2;printf("rule used: OS -> { OS }\n");fprintf(fp,"\"(%d) OS\" -> \"(%d) { OS }\"",time+1,time);time++;}
		;
		
E:		E ADD T {$$=$1+$3;printf("rule used: E -> E + T\n");fprintf(fp,"\"(%d) E\" -> \"(%d) E + T\"",time+1,time);time++;}
		| E SUB T {$$=$1-$3;printf("rule used: E -> E - T\n");fprintf(fp,"\"(%d) E\" -> \"(%d) E - T\"",time+1,time);time++;}
  		| T {$$=$1;printf("rule used: E -> T\n");fprintf(fp,"\"(%d) E\" -> \"(%d) T\"",time+1,time);time++;}
		;

T:		T MUL F {$$=$1*$3;printf("rule used: T -> T * F\n");fprintf(fp,"\"(%d) T\" -> \"(%d) T * F\"",time+1,time);time++;}
		| T DIV F {$$=$1/$3;printf("rule used: T -> T / F\n");fprintf(fp,"\"(%d) T\" -> \"(%d) T / F\"",time+1,time);time++;}
  		| F {$$=$1;printf("rule used: T -> F\n");fprintf(fp,"\"(%d) T\" -> \"(%d) F\"",time+1,time);time++;}	
  		;

F:		LPAR E RPAR {$$=$2;printf("rule used: F -> ( E )\n");fprintf(fp,"\"(%d) F\" -> \"(%d) ( E )\"",time+1,time);time++;}		
		| NUM {$$=atoi(yytext); printf("rule used: F -> num -> %d\n",$$);fprintf(fp,"\"(%d) F\" -> \"(%d) num \'%d\'\"",time+1,time,$$);time++;}
		;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
	time=1;
	fp=fopen("parse_forest.dot","wt");
	if(fp==NULL)
	{
		printf("Error opening file [parse_forest.dot]\n");
		exit(-1);
	}
	
	fprintf(fp,"digraph parse_forest {\n");
	yyparse();
	fprintf(fp,"\n}\n");
	fclose(fp);
	fp=NULL;
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
rule used: Start -> S
The final output is 1008
```
![parse forest](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/lec6ex1/parse_forest.svg)

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
shouvick@shouvick:~/CS-327-Compilers/lec6ex1$ ./stmt 
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
rule used: MS -> ; MS
rule used: MS -> ; MS
rule used: MS -> ; MS
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
rule used: Start -> S
The final output is 20
```
