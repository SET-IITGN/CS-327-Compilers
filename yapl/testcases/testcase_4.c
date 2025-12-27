
int main()
{
	iitm.chennai.cs3300(); //valid
	a.a.a.a.a.a.a.main()=9; //valid
	iitm.chennai.a=h.g(g(g())); //valid
}

int fun1()
{
	if(1)
		a++;
	else if(0) 
			b++; //1
	else 
			c++; //2 

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
	else if(9)
	{ //3
		if(1)
			a++;
		else if(0)
			b++; //4
		else
			c++; //5
	}
	else if(8)
	{ //4
		if(1)
			a++;
		else if(0)
			b++; //5
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			c++; //9
		else if(2)
			k++; //10
		else if(3)
			k++; //11
		else if(6)
			k++; //12
		else if(6)
			k++; //13
		else if(6)
			k++; //14
		else if(6)
			k++; //15
		else if(6)
			k++; //16
		else if(6)
			k++; //17 (max depth is here)		
	}
	else if(0)
	{ //5
		if(1)
			a++;
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			b++; //9
		else if(0)
			c++; //10
		else
			k++; //11		
	}

	if(1)
		a++;
	else if(0) //1
		b++;

}

int fun2()
{
	if(1)
		a++;
	else if(0) 
			b++; //1
	else 
			c++; //2 

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
	else if(9)
	{ //3
		if(1)
			a++;
		else if(0)
			b++; //4
		else
			c++; //5
	}
	else if(8)
	{ //4
		if(1)
			a++;
		else if(0)
			b++; //5
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			c++; //9
		else if(2)
			k++; //10
		else if(3)
			k++; //11
		else if(6)
			k++; //12		
	}
	else if(0)
	{ //5
		if(1)
			a++;
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			b++; //9
		else if(0)
			c++; //10
		else
			k++; //11		
	}

	if(1)
		a++;
	else if(0) //1
		b++;

}

int fun3()
{
	if(1)
		a++;
	else if(0) 
			b++; //1
	else 
			c++; //2 

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
	else if(9)
	{ //3
		if(1)
			a++;
		else if(0)
			b++; //4
		else
			c++; //5
	}
	else if(8)
	{ //4
		if(1)
			a++;
		else if(0)
			b++; //5
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			c++; //9
		else if(2)
			k++; //10
		else if(3)
			k++; //11
		else if(6)
			k++; //12
		else if(6)
			k++; //13
		else if(6)
			k++; //14
		else if(6)
			k++; //15
		else if(6)
			k++; //16
		else if(6)
			k++; //17 (max depth is here)		
	}
	else if(0)
	{ //5
		if(1)
			a++;
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			b++; //9
		else if(0)
			c++; //10
		else
			k++; //11		
	}

	if(1)
		a++;
	else if(0) //1
		b++;

}

int fun4()
{
	if(1)
		a++;
	else if(0) 
			b++; //1
	else 
			c++; //2 

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
	else if(9)
	{ //3
		if(1)
			a++;
		else if(0)
			b++; //4
		else
			c++; //5
	}
	else if(8)
	{ //4
		if(1)
			a++;
		else if(0)
			b++; //5
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			c++; //9
		else if(2)
			k++; //10
		else if(3)
			k++; //11
		else if(6)
			k++; //12		
	}
	else if(0)
	{ //5
		if(1)
			a++;
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			b++; //9
		else if(0)
			c++; //10
		else
			k++; //11		
	}

	if(1)
		a++;
	else if(0) //1
		b++;

}

int fun5()
{
	if(1)
		a++;
	else if(0) 
			b++; //1
	else 
			c++; //2 

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
	else if(9)
	{ //3
		if(1)
			a++;
		else if(0)
			b++; //4
		else
			c++; //5
	}
	else if(8)
	{ //4
		if(1)
			a++;
		else if(0)
			b++; //5
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			c++; //9
		else if(2)
			k++; //10
		else if(3)
			k++; //11
		else if(6)
			k++; //12		
	}
	else if(0)
	{ //5
		if(1)
			a++;
		else if(0)
			b++; //6
		else if(0)
			b++; //7
		else if(0)
			b++; //8
		else if(0)
			b++; //9
		else if(0)
			c++; //10
		else
			k++; //11		
	}

	if(1)
		a++;
	else if(0) //1
		b++;

}

