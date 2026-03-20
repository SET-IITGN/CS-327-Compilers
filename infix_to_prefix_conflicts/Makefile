a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o if2prfc
	@echo "Run the program as ./if2prfc < input.txt"

y.tab.c: if2prfc.y 
	yacc -d --report=itemsets,states,lookaheads -g if2prfc.y

lex.yy.c: if2prfc.l y.tab.h
	lex if2prfc.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c if2prfc *.output *.gv *.svg

