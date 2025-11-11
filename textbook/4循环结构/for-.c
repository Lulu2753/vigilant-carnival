#include <stdio.h>

int main()
{
	int n=0, i;

	for (i = 0;; i++)   //中间空着表示死循环，一直循环不停；三个都空着等于while(1)，死循环；如果条件是赋值=，而不是==，也是永真，死循环
		n += i;

	printf("%d", n);

	return 0;
}