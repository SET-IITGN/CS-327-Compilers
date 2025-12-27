
int *var=6;
struct mystruct *ms=&var;

int auto, static, inline;

extern void *k;
int p;
int p;
int p;

int *hh(char *p);

int main(int b)
{
	int auto=2,b=3,c;
	c=auto+b;
	printf("%d",c);

	struct player
	{
		int a;
		double c;
	};

	int *jj=&auto;

	System.out.print("java here");
	char echo[3]="bash here";
	myprintf("CS3300 here");
	printf(echo);

	/*
		mixing things here a bit
	*/

	if(a==9)
	{
		//NO-OP
	}
	
	if(a==1)
		hh(++jj);
	else if(a==2)
		hh(jj++);
	else if(a==3)
		hh(*jj++);
	else
	{
		//NO-OP
	}
			
	struct player *p;
	p=(struct player *)malloc(sizeof(struct player));
	
	p->a=1;
	p->b=2.4;

	//#pragma omp parallel for
	for(a=1;a<=5;a++)
		static(a);

	int *p;
	float *j;
	p=&auto;
	j=0x1234;
	printf("*j=%p",(char *)j);

	void *static=&c;

	int a=5,b=8,c;
	c=a<=>b;

	hh(p);
	
	return(0);
}	

int *hh(char *p)
{
	int n=7;

	scanf("%d",&n);
	
	if(n==0)
		printf("%d\n",n+1);
	else if(n==1)
		printf("%d\n",n+2);
	
	return(NULL);
}	
