## `ex1.l`
```
%{
#include<stdio.h>
#include<string.h>
void yyerror(char *);
int s=0,h=0,time=0;
%}

%%

she		{
			s++;
			time++;
			printf("t=%d, line %d: lexeme (%s) of length %d, --> regex \"she\" matched\n",time,yylineno,yytext,yyleng);
		}
		
he		{
			h++;
			time++;
			printf("t=%d, line %d: lexeme (%s) of length %d, --> regex \"he\" matched\n",time,yylineno,yytext,yyleng);
		}

. 		{
			char buff[1024]={'\0'}; 
			sprintf(buff,"t=%d, line %d: lexeme (%s) of length %d, --> none matched\n",time,yylineno,yytext,yyleng);
			yyerror(buff);
		}
		
\n 		{
			yylineno++;
		}

%%

void yyerror(char *msg)
{
	printf("lexical error: %s",msg);
}

int main()
{
	yylex();
	printf("he=%d,she=%d\n",h,s);
	return(0);
}
```
## `input.txt`
```
he ahe he she she fsfds fsf fs sfhe he she she she
he
hshe
hehehesheshe
```

## Command-line
```
shouvick@shouvick:~/CS327/playground/lec3ex1$ ./ex1 < input.txt 
t=1, line 1: lexeme (he) of length 2, --> regex "he" matched
lexical error: t=1, line 1: lexeme ( ) of length 1, --> none matched
lexical error: t=1, line 1: lexeme (a) of length 1, --> none matched
t=2, line 1: lexeme (he) of length 2, --> regex "he" matched
lexical error: t=2, line 1: lexeme ( ) of length 1, --> none matched
t=3, line 1: lexeme (he) of length 2, --> regex "he" matched
lexical error: t=3, line 1: lexeme ( ) of length 1, --> none matched
t=4, line 1: lexeme (she) of length 3, --> regex "she" matched
lexical error: t=4, line 1: lexeme ( ) of length 1, --> none matched
t=5, line 1: lexeme (she) of length 3, --> regex "she" matched
lexical error: t=5, line 1: lexeme ( ) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (f) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (s) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (f) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (d) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (s) of length 1, --> none matched
lexical error: t=5, line 1: lexeme ( ) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (f) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (s) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (f) of length 1, --> none matched
lexical error: t=5, line 1: lexeme ( ) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (f) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (s) of length 1, --> none matched
lexical error: t=5, line 1: lexeme ( ) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (s) of length 1, --> none matched
lexical error: t=5, line 1: lexeme (f) of length 1, --> none matched
t=6, line 1: lexeme (he) of length 2, --> regex "he" matched
lexical error: t=6, line 1: lexeme ( ) of length 1, --> none matched
t=7, line 1: lexeme (he) of length 2, --> regex "he" matched
lexical error: t=7, line 1: lexeme ( ) of length 1, --> none matched
t=8, line 1: lexeme (she) of length 3, --> regex "she" matched
lexical error: t=8, line 1: lexeme ( ) of length 1, --> none matched
t=9, line 1: lexeme (she) of length 3, --> regex "she" matched
lexical error: t=9, line 1: lexeme ( ) of length 1, --> none matched
t=10, line 1: lexeme (she) of length 3, --> regex "she" matched
t=11, line 2: lexeme (he) of length 2, --> regex "he" matched
lexical error: t=11, line 3: lexeme (h) of length 1, --> none matched
t=12, line 3: lexeme (she) of length 3, --> regex "she" matched
t=13, line 4: lexeme (he) of length 2, --> regex "he" matched
t=14, line 4: lexeme (he) of length 2, --> regex "he" matched
t=15, line 4: lexeme (he) of length 2, --> regex "he" matched
t=16, line 4: lexeme (she) of length 3, --> regex "she" matched
t=17, line 4: lexeme (she) of length 3, --> regex "she" matched
he=9,she=8
```
