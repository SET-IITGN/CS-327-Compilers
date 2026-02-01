# Ambiguous ``dangling-else`` Grammar

### Ambiguous grammar
```
stmt -> if expr then stmt
        | if expr then stmt else stmt
        | other
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

Start:	St {$$=$1;printf("rule used: Start -> St\n");fprintf(fp,"\"(%d) Start\" -> \"(%d) St\"",time+1,time);printf("The final output is %d\n",$$);time++;}
		;

St: 	IF E THEN St {$$=($2!=0)?$4:0;$$*=$2;printf("rule used: St -> if E then St\n");fprintf(fp,"\"(%d) St\" -> \"(%d) if E then St\"",time+1,time);time++;}
		| IF E THEN St ELSE St {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: St -> if E then St else St\n");fprintf(fp,"\"(%d) St\" -> \"(%d) if E then St else St\"",time+1,time);time++;}
		| SEM {$$=1;printf("rule used: St -> ;\n");fprintf(fp,"\"(%d) St\" -> \"(%d) ;\"",time+1,time);time++;}
		| SEM St {$$=$2;printf("rule used: St -> ; St\n");fprintf(fp,"\"(%d) St\" -> \"(%d) ; St\"",time+1,time);time++;}
		| LBRACE St RBRACE {$$=$2;printf("rule used: St -> { St }\n");fprintf(fp,"\"(%d) St\" -> \"(%d) { St }\"",time+1,time);time++;}
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
## ``y.output``
```
State 24 conflicts: 1 shift/reduce


Grammar

    0 $accept: Start $end

    1 Start: St

    2 St: IF E THEN St
    3   | IF E THEN St ELSE St
    4   | SEM
    5   | SEM St
    6   | LBRACE St RBRACE

    7 E: E ADD T
    8  | E SUB T
    9  | T

   10 T: T MUL F
   11  | T DIV F
   12  | F

   13 F: LPAR E RPAR
   14  | NUM


Terminals, with rules where they appear

    $end (0) 0
    error (256)
    ADD (258) 7
    MUL (259) 10
    NUM (260) 14
    SUB (261) 8
    DIV (262) 11
    THEN (263) 2 3
    SEM (264) 4 5
    IF (265) 2 3
    ELSE (266) 3
    LPAR (267) 13
    RPAR (268) 13
    LBRACE (269) 6
    RBRACE (270) 6


Nonterminals, with rules where they appear

    $accept (16)
        on left: 0
    Start (17)
        on left: 1
        on right: 0
    St (18)
        on left: 2 3 4 5 6
        on right: 1 2 3 5 6
    E (19)
        on left: 7 8 9
        on right: 2 3 7 8 13
    T (20)
        on left: 10 11 12
        on right: 7 8 9 10 11
    F (21)
        on left: 13 14
        on right: 10 11 12


State 0

    0 $accept: . Start $end

    SEM     shift, and go to state 1
    IF      shift, and go to state 2
    LBRACE  shift, and go to state 3

    Start  go to state 4
    St     go to state 5


State 1

    4 St: SEM .
    5   | SEM . St

    SEM     shift, and go to state 1
    IF      shift, and go to state 2
    LBRACE  shift, and go to state 3

    $default  reduce using rule 4 (St)

    St  go to state 6


State 2

    2 St: IF . E THEN St
    3   | IF . E THEN St ELSE St

    NUM   shift, and go to state 7
    LPAR  shift, and go to state 8

    E  go to state 9
    T  go to state 10
    F  go to state 11


State 3

    6 St: LBRACE . St RBRACE

    SEM     shift, and go to state 1
    IF      shift, and go to state 2
    LBRACE  shift, and go to state 3

    St  go to state 12


State 4

    0 $accept: Start . $end

    $end  shift, and go to state 13


State 5

    1 Start: St .

    $default  reduce using rule 1 (Start)


State 6

    5 St: SEM St .

    $default  reduce using rule 5 (St)


State 7

   14 F: NUM .

    $default  reduce using rule 14 (F)


State 8

   13 F: LPAR . E RPAR

    NUM   shift, and go to state 7
    LPAR  shift, and go to state 8

    E  go to state 14
    T  go to state 10
    F  go to state 11


State 9

    2 St: IF E . THEN St
    3   | IF E . THEN St ELSE St
    7 E: E . ADD T
    8  | E . SUB T

    ADD   shift, and go to state 15
    SUB   shift, and go to state 16
    THEN  shift, and go to state 17


State 10

    9 E: T .
   10 T: T . MUL F
   11  | T . DIV F

    MUL  shift, and go to state 18
    DIV  shift, and go to state 19

    $default  reduce using rule 9 (E)


State 11

   12 T: F .

    $default  reduce using rule 12 (T)


State 12

    6 St: LBRACE St . RBRACE

    RBRACE  shift, and go to state 20


State 13

    0 $accept: Start $end .

    $default  accept


State 14

    7 E: E . ADD T
    8  | E . SUB T
   13 F: LPAR E . RPAR

    ADD   shift, and go to state 15
    SUB   shift, and go to state 16
    RPAR  shift, and go to state 21


State 15

    7 E: E ADD . T

    NUM   shift, and go to state 7
    LPAR  shift, and go to state 8

    T  go to state 22
    F  go to state 11


State 16

    8 E: E SUB . T

    NUM   shift, and go to state 7
    LPAR  shift, and go to state 8

    T  go to state 23
    F  go to state 11


State 17

    2 St: IF E THEN . St
    3   | IF E THEN . St ELSE St

    SEM     shift, and go to state 1
    IF      shift, and go to state 2
    LBRACE  shift, and go to state 3

    St  go to state 24


State 18

   10 T: T MUL . F

    NUM   shift, and go to state 7
    LPAR  shift, and go to state 8

    F  go to state 25


State 19

   11 T: T DIV . F

    NUM   shift, and go to state 7
    LPAR  shift, and go to state 8

    F  go to state 26


State 20

    6 St: LBRACE St RBRACE .

    $default  reduce using rule 6 (St)


State 21

   13 F: LPAR E RPAR .

    $default  reduce using rule 13 (F)


State 22

    7 E: E ADD T .
   10 T: T . MUL F
   11  | T . DIV F

    MUL  shift, and go to state 18
    DIV  shift, and go to state 19

    $default  reduce using rule 7 (E)


State 23

    8 E: E SUB T .
   10 T: T . MUL F
   11  | T . DIV F

    MUL  shift, and go to state 18
    DIV  shift, and go to state 19

    $default  reduce using rule 8 (E)


State 24

    2 St: IF E THEN St .
    3   | IF E THEN St . ELSE St

    ELSE  shift, and go to state 27

    ELSE      [reduce using rule 2 (St)]
    $default  reduce using rule 2 (St)


State 25

   10 T: T MUL F .

    $default  reduce using rule 10 (T)


State 26

   11 T: T DIV F .

    $default  reduce using rule 11 (T)


State 27

    3 St: IF E THEN St ELSE . St

    SEM     shift, and go to state 1
    IF      shift, and go to state 2
    LBRACE  shift, and go to state 3

    St  go to state 28


State 28

    3 St: IF E THEN St ELSE St .

    $default  reduce using rule 3 (St)
```

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/lec6ex2$ ./stmt 
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
rule used: St -> ;
rule used: St -> ;
rule used: St -> if E then St else St
rule used: St -> if E then St
rule used: Start -> St
The final output is 1008
```
![parse forest](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/lec7ex2/parse_forest.svg)

## Command-line (test case #2)
```
shouvick@shouvick:~/CS-327-Compilers/lec6ex2$ ./stmt 
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
shouvick@shouvick:~/CS-327-Compilers/lec6ex2$ ./stmt 
if 4 then
rule used: F -> num
rule used: T -> F
rule used: E -> T
{
	if 5 then {{{{;;;;}}}} else {;}
rule used: F -> num
rule used: T -> F
rule used: E -> T
rule used: St -> ;
rule used: St -> ; St
rule used: St -> ; St
rule used: St -> ; St
rule used: St -> { St }
rule used: St -> { St }
rule used: St -> { St }
rule used: St -> { St }
rule used: St -> ;
rule used: St -> { St }
rule used: St -> if E then St else St
}
rule used: St -> { St }
rule used: St -> if E then St
rule used: Start -> St
The final output is 20
```
