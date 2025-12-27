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
