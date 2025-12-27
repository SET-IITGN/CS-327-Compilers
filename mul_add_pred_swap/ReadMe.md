## Context-free grammar (CFG) with the precedence of addition and multiplication swapped. This means ```+``` has higher precedence than ```*```  
```
E -> E * T | T      
T -> T + F | F      
F -> NUM

| Operator | Precedence | Associativity |
| -------- | ---------- | ------------- |
| +        | Higher     | Left          |
| *        | Lower      | Left          |
```
Numbers: Arbitrary length via lexer [0-9]+ → single NUM token

### Lexical Analyzer (scanner)
```
%{
	#include <stdlib.h>
	#include "y.tab.h"
	extern char mytext[];
%}

%%

"+"		{return ADD;}
"*"  	{return MUL;}
[0-9]+	{strcpy(mytext, yytext); return NUM;}
.|\n	{;}

%%

int yywrap(void) {
    return 1;
}
```
### Syntax Analyzer (parser)
```
%token ADD MUL NUM
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

S:	E {$$=$1;printf("%d\n",$$);}
    ;
	
E:	E MUL T {$$=$1*$3;}
  	| T {$$=$1;}
    ;

T:	T ADD F {$$=$1+$3;}
  	| F {$$=$1;}	
  	;

F:	NUM {$$=atoi(yytext);}
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
## Makefile for building the compiler
```
a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o maps
	@echo "Run the program as ./maps < input.txt"

y.tab.c: mul_add_pred_swap.y 
	yacc -d mul_add_pred_swap.y

lex.yy.c: mul_add_pred_swap.l y.tab.h
	lex mul_add_pred_swap.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c maps
```
---
```
$ make
gcc lex.yy.c y.tab.c -o maps
Run the program as ./maps < input.txt
```
## Executing the compiler (language processor)
```
$ ./maps
10+5
15
```
---
```
$ ./maps
10+5*7
105
```
---
```
$ ./maps
10+(-7)
17
```
---
```
$ ./maps
--5
5
```
---
```
$ ./maps
3+
syntax error
```
---
```
$ ./maps
4+9*(7)
91
```
---
```
$ ./maps
(8((
8
```
---
```
$ ./maps
int a=8;
int b=a+8*2;
printf("%d",b);
32
```
---
```
$ ./maps
a=8;
kuch bhi;
+5*iitgn
4
52
```
## Observation
***The way you specify a programming language (syntax + semantics) determines what you deploy through software written in that language, including bugs (features).***
