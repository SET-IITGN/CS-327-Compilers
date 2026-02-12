a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o if2pf
	@echo "Run the program as ./if2pf < input.txt"

y.tab.c: if2pf.y 
	yacc -d if2pf.y

lex.yy.c: if2pf.l y.tab.h
	lex if2pf.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c if2pf

