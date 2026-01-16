## `ex2.l`
```
%{
#include<stdio.h>
%}

%%

a(a|b)*a {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} that start and end with a\n",yytext);REJECT;}

(a|b)*a(a|b)(a|b) {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} with third last letter as a\n",yytext);REJECT;}

a*ba*ba*ba* {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} with exactly three bs\n",yytext);REJECT;}

((a|b)(a|b))* {printf("lexeme (%s) matches the regex for strings over alphabet {a, b} with even length\n",yytext);REJECT;}

. {printf("lexeme (%s) does not match any regex of our interest\n",yytext);}

%%

int main()
{
	yylex();
	return(0);
}
```
## `input.txt`
```
abababababa
aaaaa
aaaaa
ababababbabababab
bbbbbbbbbbbbbbbbbbbbbbbbb
ababaa
bbbbaaaabbbb
ababb
```

## Command-line
```
shouvick@shouvick:~/CS327/playground/lec3ex2$ ./ex2 < input.txt
lexeme (abababababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bababababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (ababababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (babababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (a) does not match any regex of our interest

lexeme (aaaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (a) does not match any regex of our interest

lexeme (aaaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (a) does not match any regex of our interest

lexeme (ababababbabababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababababbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababababbabababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababababbababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababababbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababababbababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababababbaba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababababbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababababbaba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababababba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababababba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababababb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (babababbabababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babababbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababbababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babababbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababbabab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babababbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababbab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babababb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abababbabababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababbabababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababbababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababbababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababbaba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababbaba) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababba) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bababbabababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababbababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababbabab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababbab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababb) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (ababbabababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababbabababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababbababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababbababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababbaba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababbaba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababba) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (babbabababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babbababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babbabab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babbab) matches the regex for strings over alphabet {a, b} with even length
lexeme (babba) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (babb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (babb) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abbabababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abbabababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (abbababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abbababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (abbaba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abbaba) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (abbaba) matches the regex for strings over alphabet {a, b} with even length
lexeme (abbab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (abba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abba) matches the regex for strings over alphabet {a, b} with even length
lexeme (abb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bbabababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbabababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbabab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbaba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbaba) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (babababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (abababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bababa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bababa) matches the regex for strings over alphabet {a, b} with even length
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (ababab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (ababab) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (babab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (b) does not match any regex of our interest

lexeme (bbbbbbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (b) does not match any regex of our interest

lexeme (ababaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (ababa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (ababa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (baba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baba) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (abaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (a) does not match any regex of our interest

lexeme (bbbbaaaabbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbaaaabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbbaaaabb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbaaaab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbbaaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbbaaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbbaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbbaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbbaaaabbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbaaaabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbaaaab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbaaaab) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbaaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbaaaa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbbaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbbaaa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbbaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbbaa) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbba) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbba) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbaaaabbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbaaaabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbaaaabb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbaaaab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbaaaab) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bbaaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbaaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (bbaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (baaaabbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (baaaabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baaaabb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (baaaab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baaaab) matches the regex for strings over alphabet {a, b} with even length
lexeme (baaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (baaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (aaaabbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaaabbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (aaaabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaabb) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaaab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaaa) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aaabbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (aaabbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aaab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aaa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aaa) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (aabbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (aabbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (aabb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aabb) matches the regex for strings over alphabet {a, b} with even length
lexeme (aab) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (aa) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aa) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (abbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (abbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (abb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bbbb) matches the regex for strings over alphabet {a, b} with even length
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bbb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (b) does not match any regex of our interest

lexeme (ababb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ababb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (abab) matches the regex for strings over alphabet {a, b} with even length
lexeme (aba) matches the regex for strings over alphabet {a, b} that start and end with a
lexeme (aba) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (babb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (babb) matches the regex for strings over alphabet {a, b} with exactly three bs
lexeme (babb) matches the regex for strings over alphabet {a, b} with even length
lexeme (ba) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (abb) matches the regex for strings over alphabet {a, b} with third last letter as a
lexeme (ab) matches the regex for strings over alphabet {a, b} with even length
lexeme (a) does not match any regex of our interest
lexeme (bb) matches the regex for strings over alphabet {a, b} with even length
lexeme (b) does not match any regex of our interest
lexeme (b) does not match any regex of our interest

```
