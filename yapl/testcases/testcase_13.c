
int main(int *argc, char argv[]){

	int static, auto;
	char goto, restrict;
	double volatile;
	char *restrict;

	volatile = 2.435;
	union = 2.33;
	goto = 6;
	restrict = "Hello Foobar";

	return 0;
}

int fun()
{
	if(1)
		a++;
	else if(0) //1
		b++;
	else if(1)
	{ //2
		if(1)
			a++;
		else if(0) 
			b++; //3
		else 
			c++; //4 
	}
	else
	{ //3
		if(1)
			a++;
		else if(0)
			b++; //4
		else
			c++; //5 (max depth is here)	
	}
}
