# Infix to Postfix Translation

## ``if2pf.l``
```
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
```
## ``if2pf.y``
```
%union
{
	int val;
	char buff[1024];
}

%token <buff> ADD SUB MUL DIV LPAR RPAR
%token <buff> NUM
%type  <buff> S Expr Term Factor

%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	void yyerror(char *);
	int yylex(void);
	char aux[256];
	extern char *yytext;
%}
%start S

%%

S:	    Expr {strcpy($$,$1);printf("S: %s\n\n%s\n",$$,$$);}
	    ;
	
Expr:   Expr ADD Term {strcpy(aux,"\0");strcat(aux,$1);strcat(aux,$3);strcat(aux,"+");strcpy($$,aux);printf("Expr: %s\n",$$);}
  	    | Expr SUB Term {strcpy(aux,"\0");strcat(aux,$1);strcat(aux,$3);strcat(aux,"-");strcpy($$,aux);printf("Expr: %s\n",$$);}
  	    | Term {strcpy($$,$1);printf("Expr: %s\n",$$);}
	    ;

Term:   Term MUL Factor {strcpy(aux,"\0");strcat(aux,$1);strcat(aux,$3);strcat(aux,"*");strcpy($$,aux);printf("Term: %s\n",$$);}
  	    | Term DIV Factor {strcpy(aux,"\0");strcat(aux,$1);strcat(aux,$3);strcat(aux,"/");strcpy($$,aux);printf("Term: %s\n",$$);}
  	    | Factor {strcpy($$,$1);printf("Term: %s\n",$$);}
  	    ;

Factor:	LPAR Expr RPAR {strcpy($$,$2);printf("Factor: %s\n",$$);}
	    | NUM {strcpy($$,$1);printf("Factor: %s\n",$$);}
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
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
2 + 2
Factor: 2
Term: 2
Expr: 2
Factor: 2
Term: 2
Expr: 22+
S: 22+

22+
```
## Command-line (test case #2)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
a+2/6+7*5
Factor: a
Term: a
Expr: a
Factor: 2
Term: 2
Factor: 6
Term: 26/
Expr: a26/+
Factor: 7
Term: 7
Factor: 5
Term: 75*
Expr: a26/+75*+
S: a26/+75*+

a26/+75*+
```
## Command-line (test case #3)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
(a+b)*c-(d-e)^(f+g) 
Factor: a
Term: a
Expr: a
Factor: b
Term: b
Expr: ab+
Factor: ab+
Term: ab+
Factor: c
Term: ab+c*
Expr: ab+c*
Factor: d
Term: d
Expr: d
Factor: e
Term: e
Expr: de-
Factor: de-
Term: de-
Expr: ab+c*de--
S: ab+c*de--

ab+c*de--
syntax error
```
## Command-line (test case #4)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
(a+b)*c-(d-e)/(f+g)+(1)+(A+B*C/D)                             
Factor: a
Term: a
Expr: a
Factor: b
Term: b
Expr: ab+
Factor: ab+
Term: ab+
Factor: c
Term: ab+c*
Expr: ab+c*
Factor: d
Term: d
Expr: d
Factor: e
Term: e
Expr: de-
Factor: de-
Term: de-
Factor: f
Term: f
Expr: f
Factor: g
Term: g
Expr: fg+
Factor: fg+
Term: de-fg+/
Expr: ab+c*de-fg+/-
Factor: 1
Term: 1
Expr: 1
Factor: 1
Term: 1
Expr: ab+c*de-fg+/-1+
Factor: A
Term: A
Expr: A
Factor: B
Term: B
Factor: C
Term: BC*
Factor: D
Term: BC*D/
Expr: ABC*D/+
Factor: ABC*D/+
Term: ABC*D/+
Expr: ab+c*de-fg+/-1+ABC*D/++
S: ab+c*de-fg+/-1+ABC*D/++

ab+c*de-fg+/-1+ABC*D/++
```
## Command-line (test case #5) on-the-fly
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
a 
Factor: a
Term: a
*
a
Factor: a
Term: aa*
+  
Expr: aa*
b
Factor: b
Term: b
*
b
Factor: b
Term: bb*
+
Expr: aa*bb*+
2 
Factor: 2
Term: 2
*
a
Factor: a
Term: 2a*
*
b
Factor: b
Term: 2a*b*
Expr: aa*bb*+2a*b*+
S: aa*bb*+2a*b*+

aa*bb*+2a*b*+
```
## Command-line (test case #6)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
aa+bb+ab+ab
Factor: aa
Term: aa
Expr: aa
Factor: bb
Term: bb
Expr: aabb+
Factor: ab
Term: ab
Expr: aabb+ab+
Factor: ab
Term: ab
Expr: aabb+ab+ab+
S: aabb+ab+ab+

aabb+ab+ab+
```
## Command-line (test case #7)
```
shouvick@shouvick:~/CS-327-Compilers/infix_to_postfix$ ./if2pf 
a+(a+(a+(a+1)))
Factor: a
Term: a
Expr: a
Factor: a
Term: a
Expr: a
Factor: a
Term: a
Expr: a
Factor: a
Term: a
Expr: a
Factor: 1
Term: 1
Expr: a1+
Factor: a1+
Term: a1+
Expr: aa1++
Factor: aa1++
Term: aa1++
Expr: aaa1+++
Factor: aaa1+++
Term: aaa1+++
Expr: aaaa1++++
S: aaaa1++++

aaaa1++++
```
