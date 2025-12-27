int a, b, c;

int main(int *argc, char* argv[])
{
	int a, i;
	int b[10];
	for(i=1; i<=10; ++i) {
		b[i-1] = i*i;		// square
	}
	int *c = b;
	i = 0;
	int d= 0;
	while(i<10) {
		d += *(c + i);
	}
	printf("%d\n", d);	// print sum of values
	return 0;
}
