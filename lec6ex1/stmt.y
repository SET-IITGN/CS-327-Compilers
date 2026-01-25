%token ADD MUL NUM SUB DIV THEN SEM IF ELSE LPAR RPAR LBRACE RBRACE
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

S:		MS {printf("rule used: S -> MS\n");}
		| OS {printf("rule used: S -> OS\n");}
		;

MS: 	IF E THEN MS ELSE MS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: MS -> if E then MS else MS\n");}
		| SEM {$$=1;printf("rule used: MS -> ;\n");}
		| SEM MS {$$=1;printf("rule used: MS -> MS ;\n");}
		| LBRACE MS RBRACE {printf("rule used: MS -> { MS }\n");}
		;
		
OS:		IF E THEN S {$$=($2!=0)?$4:0;$$*=$2;printf("rule used: OS -> if E then S\n");}
		| IF E THEN MS ELSE OS {$$=($2!=0)?$4:$6;$$*=$2;printf("rule used: OS -> if E then MS else OS\n");}
		| LBRACE OS RBRACE {printf("rule used: OS -> { OS }\n");}
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
