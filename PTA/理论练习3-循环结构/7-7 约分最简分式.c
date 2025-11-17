#include <stdio.h>

int main()
{
	int a, b,i=1;
	scanf_s("%d/%d", &a, &b);

	if (a > b)
		i = b;
	else if (a <= b)
		i = a;

	while (a % i != 0 || b % i != 0)   //最大公约数条件：a%i==0&&b%i==0，此处需要否命题，改变逻辑词
		i--;

	printf("%d/%d", a / i, b / i);

	return 0;
}