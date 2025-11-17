#include <stdio.h>

int main()
{
	char ch = 0;
	
	while (ch != '\n')
	{
		ch = getchar();
		if (ch == '\n')
			break;      //要先判断是否为换行，否则是在循环内部输入换行并且执行，执行完之后再从循环出来
		else if (ch == 'C' || ch == 'c')
			printf("BEIJING OLYMPIC GAMES\n");
		else if (ch == 'J' || ch == 'j')
			printf("JAPAN WORLD CUP\n");
		else if (ch == 'K' || ch == 'k')
			printf("KOREA WORLD CUP\n");
		else
			printf("%c\n", ch);
	}

	return 0;
}