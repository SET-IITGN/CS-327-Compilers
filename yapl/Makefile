yapl: y.tab.c lex.yy.c
	gcc -O3 lex.yy.c y.tab.c -o yapl
	@echo "Run the program as ./yapl [input_file]"

y.tab.c: yapl.y 
	yacc -d yapl.y

lex.yy.c: yapl.l y.tab.h
	lex yapl.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c yapl

