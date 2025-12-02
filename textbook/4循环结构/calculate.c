#include <stdio.h>

int main()

/*没办法做到三个因子运算*/

{
	float l, f;
	char ch;

	while (scanf_s("%f", &l) == 1)     //可以直接在这里输入，不用单独scanf
	{
		ch = getchar();
		if ((ch != '+' && ch != '-' && ch != '*' && ch != '/') || scanf_s("%f", &f) != 1)    //表示读进去的值
		{
			while (getchar() == '=')    //持续读取符号，直到出现等于号
				break;  //continue是忽略当前循环的后续语句，直接进入下一次循环，而不跳出循环

			while (getchar() == '\n')
				continue;
		}
	}

	switch (ch)
	{
	case '+':
		printf("%g\n", l + f);
		break;

	case '-':
		printf("%g\n", l - f);
		break;

	case '*':
		printf("%g\n", l * f);
		break;

	case '/':
		if (f != 0)
		{
			printf("%g\n", l / f);

		}
		else
			printf("Error! Divider is 0!\n");

	}

	return 0;
}