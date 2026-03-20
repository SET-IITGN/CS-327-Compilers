%token ADD MUL LPAR RPAR NUM

%{
	#include<stdio.h>
	#include<stdlib.h>
	void yyerror(char *);
	int yylex(void);
	extern char *yytext;
%}
%start S

%%

S:	E
	;
		
E:	{printf("+");} E ADD T
	| T
	;

T:	{printf("*");} T MUL F
	| F
	;
	
F:	LPAR E RPAR
	| NUM {printf("%d",$1);}

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}

