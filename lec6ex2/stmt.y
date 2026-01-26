%token ADD MUL NUM SUB DIV THEN SEM IF ELSE LPAR RPAR LBRACE RBRACE
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

Start:	St {$$=$1;printf("rule used: Start -> St\n");printf("The final output is %d\n",$$);}
		;

St: 	IF E THEN St {$$=($2!=0)?$4:0;$$*=$2;printf("rule used: St -> if E then St\n");}
		| IF E THEN St ELSE St {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: St -> if E then St else St\n");}
		| SEM {$$=1;printf("rule used: St -> ;\n");}
		| SEM St {$$=$2;printf("rule used: St -> ; St\n");}
		| LBRACE St RBRACE {$$=$2;printf("rule used: St -> { St }\n");}
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
