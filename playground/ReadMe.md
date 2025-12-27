This is your playground!
----

```
/*
Filenamne: hello.s
example code written in the x86 assembly language (AT&T syntax)
*/
global:
	.string "hello%d\n"
	.globl	main
global2:
	.string	"%d\n"
main:
	push	%rbp
	mov	%rsp, %rbp
	sub	$16, %rsp
	mov	$5, -12(%rbp)
	mov	$6, -8(%rbp)
	mov	$0, -4(%rbp)
	mov	-12(%rbp), %edx
	mov	-8(%rbp), %eax
	add	%edx, %eax
	mov	%eax, -4(%rbp)
	mov	-4(%rbp), %eax
	mov	%eax, %esi
	lea	global2(%rip), %rax
	/*ojjl;jl;lj
	xvbcvb*/
	mov	%rax, %rdi
	mov	$0, %eax
	call printf
	mov	$0, %eax
	leave
	ret
```

---
```
~$ uname -r
5.4.0-42-generic

~$ gcc --version
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0

~$ gcc hello.s
hello.s: Assembler messages:
hello.s:13: Warning: no instruction mnemonic suffix given and no register operands; using default for `mov'
hello.s:14: Warning: no instruction mnemonic suffix given and no register operands; using default for `mov'
hello.s:15: Warning: no instruction mnemonic suffix given and no register operands; using default for `mov'

~$ ./a.out
11
```
