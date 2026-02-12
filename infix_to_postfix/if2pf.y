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

