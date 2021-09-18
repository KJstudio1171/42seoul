#include <stdlib.h>
#include <stdio.h>

void print_stack(int n, char *stack) {
	for (int i = 0; i <= n; i++)
	{
		printf("%d", stack[i]);
	}
	printf("%c",',');
}

void reflection(int n,int m, char *stack){
	if (n>=m)
	{
		print_stack(n-1, stack);
		return;
	}
	if (n-1 < 0)
	{
		for (int i = n; i < 10 - n +1; i++)
	{
		stack[n] = i;
		reflection (n + 1,m, stack);
	}
	}
	else{
		for (int i = stack[n-1] + 1; i < 10 - (m-n) +1; i++)
	{
		stack[n] = i;
		reflection (n + 1,m, stack);
	}
	}	
}

int main()
{
	int m = 9;
	char stack[10] = {0};
	reflection(0,m,stack);
}
