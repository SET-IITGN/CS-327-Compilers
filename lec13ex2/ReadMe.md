# Bottom-Up parsing: LR(0) automaton and SLR(1) parsing table
### Grammar (l-values and r-values)
```
S → L = R | R
L → *R | id
R → L
```

## ``lec13ex2.l``
```
%{
	#include <stdlib.h>
	#include <string.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

[a-z A-Z]	{strcpy(mytext, yytext); return ID;}
'='|'*'		{return(*yytext);}
.|\n		{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``lec13ex2.y``
```
%token ID
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

Start: 	S {printf("Rule used: Start -> S\n");}
		;

S:		L '=' R {printf("Rule used: S -> L = R\n");}
		| R	{printf("Rule used: S -> R\n");}
		;

L:		'*' R {printf("Rule used: L -> * R\n");}
		| ID {printf("Rule used: L -> ID\n");}
		;

R:		L {printf("Rule used: R -> L\n");}
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
	gcc lex.yy.c y.tab.c -o lec13ex2
	@echo "Run the program as ./lec13ex2 < input.txt"

y.tab.c: lec13ex2.y 
	yacc -d --report=itemsets,states -g lec13ex2.y

lex.yy.c: lec13ex2.l y.tab.h
	lex lec13ex2.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex2 *.output *.gv
```
## ``y.output``
```
Grammar

    0 $accept: Start $end

    1 Start: S

    2 S: L '=' R
    3  | R

    4 L: '*' R
    5  | ID

    6 R: L


Terminals, with rules where they appear

    $end (0) 0
    '*' (42) 4
    '=' (61) 2
    error (256)
    ID (258) 5


Nonterminals, with rules where they appear

    $accept (6)
        on left: 0
    Start (7)
        on left: 1
        on right: 0
    S (8)
        on left: 2 3
        on right: 1
    L (9)
        on left: 4 5
        on right: 2 6
    R (10)
        on left: 6
        on right: 2 3 4


State 0

    0 $accept: . Start $end
    1 Start: . S
    2 S: . L '=' R
    3  | . R
    4 L: . '*' R
    5  | . ID
    6 R: . L

    ID   shift, and go to state 1
    '*'  shift, and go to state 2

    Start  go to state 3
    S      go to state 4
    L      go to state 5
    R      go to state 6


State 1

    5 L: ID .

    $default  reduce using rule 5 (L)


State 2

    4 L: . '*' R
    4  | '*' . R
    5  | . ID
    6 R: . L

    ID   shift, and go to state 1
    '*'  shift, and go to state 2

    L  go to state 7
    R  go to state 8


State 3

    0 $accept: Start . $end

    $end  shift, and go to state 9


State 4

    1 Start: S .

    $default  reduce using rule 1 (Start)


State 5

    2 S: L . '=' R
    6 R: L .

    '='  shift, and go to state 10

    $default  reduce using rule 6 (R)


State 6

    3 S: R .

    $default  reduce using rule 3 (S)


State 7

    6 R: L .

    $default  reduce using rule 6 (R)


State 8

    4 L: '*' R .

    $default  reduce using rule 4 (L)


State 9

    0 $accept: Start $end .

    $default  accept


State 10

    2 S: L '=' . R
    4 L: . '*' R
    5  | . ID
    6 R: . L

    ID   shift, and go to state 1
    '*'  shift, and go to state 2

    L  go to state 7
    R  go to state 11


State 11

    2 S: L '=' R .

    $default  reduce using rule 2 (S)
```
![LR(0) Automaton](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/lec13ex2/y.svg)

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/lec13ex2$ ./lec13ex2
a=6
Rule used: L -> ID
Rule used: R -> L
Rule used: S -> R
Rule used: Start -> S
```
