#include <stdio.h>

int main()
{
	int amount = 0;
	int price = 0;

	printf("Please enter the price:");
	scanf_s("%d", &price);

	printf("Please enter your cash price:");
	scanf_s("%d", &amount);

	printf("The change is:%d\n", amount-price);

	return 0;
}