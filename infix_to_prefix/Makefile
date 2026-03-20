a.out: y.tab.c lex.yy.c
	gcc lex.yy.c y.tab.c -o if2prf
	@echo "Run the program as ./if2prf < input.txt"

y.tab.c: if2prf.y 
	yacc -d --report=itemsets,states,lookaheads -g if2prf.y

lex.yy.c: if2prf.l y.tab.h
	lex if2prf.l

clean:
	@rm -f lex.yy.c y.tab.h y.tab.c if2prf *.output *.gv *.svg

