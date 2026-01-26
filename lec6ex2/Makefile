a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o stmt
	@echo "Run the program as ./stmt < input.txt"

y.tab.c: stmt.y 
	yacc -d --report states stmt.y

lex.yy.c: stmt.l y.tab.h
	lex stmt.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c stmt *.dot *.output

