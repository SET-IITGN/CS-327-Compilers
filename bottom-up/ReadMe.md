# Bottom-Up parsing: LR parsing and LR(0) Automaton

## ``bottom-up.l``
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

"+"			{return ADD;}
"*" 		{return MUL;}
"(" 		{return LPAR;}
")" 		{return RPAR;}
[0-9]+		{strcpy(mytext, yytext); return NUM;}
.|\n		{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``bottom-up.y``
```
%token ADD MUL NUM LPAR RPAR
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	char mytext[100];
	extern char *yytext;
%}
%start Start

%%

Start: 	E 
		{
			$$=$1;
			printf("rule used: Start -> E\n");
			printf("The final output is %d\n",$$);
		}
		;

E:		E ADD T 
		{
			$$=$1+$3;
			printf("rule used: E -> E + T\n");
		}
  		| T 
  		{
  			$$=$1;
  			printf("rule used: E -> T\n");
  		}
		;

T:		T MUL F 
		{
			$$=$1*$3;
			printf("rule used: T -> T * F\n");
		}
  		| F 
  		{
  			$$=$1;
  			printf("rule used: T -> F\n");
  		}	
  		;

F:		LPAR E RPAR 
		{
			$$=$2;
			printf("rule used: F -> ( E )\n");
		}		
		| NUM 
		{
			$$=atoi(yytext);
			printf("rule used: F -> id [%d]\n",$$);
		}
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
## ``Makefile``
```
a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o bottom-up
	@echo "Run the program as ./bottom-up < input.txt"

y.tab.c: bottom-up.y 
	yacc -d --report=itemsets,states -g bottom-up.y

lex.yy.c: bottom-up.l y.tab.h
	lex bottom-up.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c bottom-up *.output *.gv
```
## ``y.output``
```
Grammar

    0 $accept: Start $end

    1 Start: E

    2 E: E ADD T
    3  | T

    4 T: T MUL F
    5  | F

    6 F: LPAR E RPAR
    7  | NUM


Terminals, with rules where they appear

    $end (0) 0
    error (256)
    ADD (258) 2
    MUL (259) 4
    NUM (260) 7
    LPAR (261) 6
    RPAR (262) 6


Nonterminals, with rules where they appear

    $accept (8)
        on left: 0
    Start (9)
        on left: 1
        on right: 0
    E (10)
        on left: 2 3
        on right: 1 2 6
    T (11)
        on left: 4 5
        on right: 2 3 4
    F (12)
        on left: 6 7
        on right: 4 5


State 0

    0 $accept: . Start $end
    1 Start: . E
    2 E: . E ADD T
    3  | . T
    4 T: . T MUL F
    5  | . F
    6 F: . LPAR E RPAR
    7  | . NUM

    NUM   shift, and go to state 1
    LPAR  shift, and go to state 2

    Start  go to state 3
    E      go to state 4
    T      go to state 5
    F      go to state 6


State 1

    7 F: NUM .

    $default  reduce using rule 7 (F)


State 2

    2 E: . E ADD T
    3  | . T
    4 T: . T MUL F
    5  | . F
    6 F: . LPAR E RPAR
    6  | LPAR . E RPAR
    7  | . NUM

    NUM   shift, and go to state 1
    LPAR  shift, and go to state 2

    E  go to state 7
    T  go to state 5
    F  go to state 6


State 3

    0 $accept: Start . $end

    $end  shift, and go to state 8


State 4

    1 Start: E .
    2 E: E . ADD T

    ADD  shift, and go to state 9

    $default  reduce using rule 1 (Start)


State 5

    3 E: T .
    4 T: T . MUL F

    MUL  shift, and go to state 10

    $default  reduce using rule 3 (E)


State 6

    5 T: F .

    $default  reduce using rule 5 (T)


State 7

    2 E: E . ADD T
    6 F: LPAR E . RPAR

    ADD   shift, and go to state 9
    RPAR  shift, and go to state 11


State 8

    0 $accept: Start $end .

    $default  accept


State 9

    2 E: E ADD . T
    4 T: . T MUL F
    5  | . F
    6 F: . LPAR E RPAR
    7  | . NUM

    NUM   shift, and go to state 1
    LPAR  shift, and go to state 2

    T  go to state 12
    F  go to state 6


State 10

    4 T: T MUL . F
    6 F: . LPAR E RPAR
    7  | . NUM

    NUM   shift, and go to state 1
    LPAR  shift, and go to state 2

    F  go to state 13


State 11

    6 F: LPAR E RPAR .

    $default  reduce using rule 6 (F)


State 12

    2 E: E ADD T .
    4 T: T . MUL F

    MUL  shift, and go to state 10

    $default  reduce using rule 2 (E)


State 13

    4 T: T MUL F .

    $default  reduce using rule 4 (T)
```

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/bottom-up$ ./bottom-up
6*9
rule used: F -> id [6]
rule used: T -> F
rule used: F -> id [9]
rule used: T -> T * F
rule used: E -> T
rule used: Start -> E
The final output is 54
```
