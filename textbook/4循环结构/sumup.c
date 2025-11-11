#include <stdio.h>

int main()
{
	int s = 0, i = 1,j=1,s2=0;

	do
	{
		s = s + i;
		++i;   //返回原来的值加1，才能在第100个结束后跳出循环；事实上i++也可以，不论顺序，最终的结果是i加了1，只是返回值有区别
	} while (i <= 100);  //do-while 完整语句最后有分号



	do
	{
		s2 += j++;  //s加的是j原来的值，加完后j再加1；即s加的是j返回原来的值，然后再加1
	} while (j <= 100);

		printf("%d\n %d\n", s,s2);

	return 0;

}
