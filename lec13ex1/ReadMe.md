# Bottom-Up parsing: LR(0) automaton and SLR(1) parsing table
### Grammar
```
S → A S | b
A → S A | a
```

## ``lec13ex1.l``
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

a|b		{return(*yytext);}
.|\n		{;}

%%

int yywrap(void) {
    return 1;
}
```
## ``lec13ex1.y``
```
%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
%}
%start Start

%%

Start: 	S {printf("Rule used: Start -> S\n");}
		;

S:		A S {printf("Rule used: S -> A S\n");}
		| 'b' {printf("Rule used: S -> b\n");}
		;
		
A:		S A {printf("Rule used: A -> S A\n");}
		| 'a' {printf("Rule used: A -> a\n");}
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
	gcc lex.yy.c y.tab.c -o lec13ex1
	@echo "Run the program as ./lec13ex1 < input.txt"

y.tab.c: lec13ex1.y 
	yacc -d --report=itemsets,states -g lec13ex1.y

lex.yy.c: lec13ex1.l y.tab.h
	lex lec13ex1.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c lec13ex1 *.output *.gv
```
## ``y.output``
```
Rules useless in parser due to conflicts

    4 A: S A


State 8 conflicts: 2 shift/reduce
State 9 conflicts: 2 shift/reduce


Grammar

    0 $accept: Start $end

    1 Start: S

    2 S: A S
    3  | 'b'

    4 A: S A
    5  | 'a'


Terminals, with rules where they appear

    $end (0) 0
    'a' (97) 5
    'b' (98) 3
    error (256)


Nonterminals, with rules where they appear

    $accept (5)
        on left: 0
    Start (6)
        on left: 1
        on right: 0
    S (7)
        on left: 2 3
        on right: 1 2 4
    A (8)
        on left: 4 5
        on right: 2 4


State 0

    0 $accept: . Start $end
    1 Start: . S
    2 S: . A S
    3  | . 'b'
    4 A: . S A
    5  | . 'a'

    'b'  shift, and go to state 1
    'a'  shift, and go to state 2

    Start  go to state 3
    S      go to state 4
    A      go to state 5


State 1

    3 S: 'b' .

    $default  reduce using rule 3 (S)


State 2

    5 A: 'a' .

    $default  reduce using rule 5 (A)


State 3

    0 $accept: Start . $end

    $end  shift, and go to state 6


State 4

    1 Start: S .
    2 S: . A S
    3  | . 'b'
    4 A: . S A
    4  | S . A
    5  | . 'a'

    'b'  shift, and go to state 1
    'a'  shift, and go to state 2

    $default  reduce using rule 1 (Start)

    S  go to state 7
    A  go to state 8


State 5

    2 S: . A S
    2  | A . S
    3  | . 'b'
    4 A: . S A
    5  | . 'a'

    'b'  shift, and go to state 1
    'a'  shift, and go to state 2

    S  go to state 9
    A  go to state 5


State 6

    0 $accept: Start $end .

    $default  accept


State 7

    2 S: . A S
    3  | . 'b'
    4 A: . S A
    4  | S . A
    5  | . 'a'

    'b'  shift, and go to state 1
    'a'  shift, and go to state 2

    S  go to state 7
    A  go to state 8


State 8

    2 S: . A S
    2  | A . S
    3  | . 'b'
    4 A: . S A
    4  | S A .
    5  | . 'a'

    'b'  shift, and go to state 1
    'a'  shift, and go to state 2

    'b'  [reduce using rule 4 (A)]
    'a'  [reduce using rule 4 (A)]

    S  go to state 9
    A  go to state 5


State 9

    2 S: . A S
    2  | A S .
    3  | . 'b'
    4 A: . S A
    4  | S . A
    5  | . 'a'

    'b'  shift, and go to state 1
    'a'  shift, and go to state 2

    'b'       [reduce using rule 2 (S)]
    'a'       [reduce using rule 2 (S)]
    $default  reduce using rule 2 (S)

    S  go to state 7
    A  go to state 8
```
![LR(0) Automaton](https://github.com/SET-IITGN/CS-327-Compilers/blob/main/lec13ex1/y.svg)

## Command-line (test case #1)
```
shouvick@shouvick:~/CS-327-Compilers/lec13ex1$ ./lec13ex1 
abab
Rule used: A -> a
Rule used: S -> b
Rule used: A -> a
Rule used: S -> b
Rule used: S -> A S
syntax error
```
