#include <stdio.h>

int main()
{
	int a, b,max;
	scanf_s("%d%d",&a,&b);
	
	max = (a > b) ? a : b;   //if(a>b),printf a; else, printf b; ? :
	printf("%d", max);

	return 0;
}