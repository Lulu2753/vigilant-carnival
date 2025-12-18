#include <stdio.h>

int main()
{
	int* p, a = 2, * q;

	p = &a;

	q = p + 2;

	printf("%d %d %d\n", p, q, q - p);    //p和q相差两个sizeofint=4，但是真正相减又会除掉，因为要表示相差的元素数

	return 0;
}