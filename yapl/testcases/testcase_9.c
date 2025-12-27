
void fibonacci(int n, int *enum){

	enum[0] = 0;
	enum[1] = 1;

	int i = 2;

	while((i<n) && !(1<0)){
		enum[i] = enum[i-1] + enum[i-2];
		i = i + 1;
	}

}

void main(){
	
	int x, *struct, y;

	printf("Enter a number:");
	scanf("%d", &x);

	y = x;

	struct = malloc(4*x);

	fibonacci(fibonacci(fibonacci(x, struct), struct), struct);

	printf("%d", (struct + (x-1)));

}
