int main()
{
	/*----valid-----*/

	6=8++;
	6=h++;
	d()++=6;
	*((10+1)*u)=(3+7);
	2=2;
	++2=2--;
	(a+a)=2*a; //notice the paranthesis, without which this is invalid (see below)
	-a=7;
	--a=7;
	-fun((10+1)=x); //notice the paranthesis, without which this is invalid (see below)
	-8=7;
	y(x)=f(x)+g(x);
	func((y(x)+c)=f(x)+g(x)); //notice the paranthesis, without which this is invalid (see below)
	
	//a+a=2*a; (this is invalid for this assignment)
	//fun(a+a=2*a); (this is invalid for this assignment)
	//fun(10+1=x); (this is invalid for this assignment)
	//func(y(x)+c=f(x)+g(x)); (this is invalid for this assignment)

}

/*

***parsing successful***
#global_declarations = 1
#function_definitions = 1
#integer_constants = 19
#pointers_declarations = 0
#ifs_without_else = 0
if-else max-depth = 0

*/
