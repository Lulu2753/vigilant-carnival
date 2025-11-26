#include <stdio.h>

int main()
{
	float l, f;
	char ch;

	while (scanf_s("%f", &l) == 1)     //可以直接在这里输入，不用单独scanf
	{
		ch = getchar();
		if ((ch != '+' && ch != '-' && ch != '*' && ch != '/') || scanf_s("%f", &f) != 1)
		{
			while (getchar() == '=')
				break;        //continue是忽略当前循环的后续语句，直接进入下一次循环
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
			printf("Error! Devider is 0!\n");

	}

	return 0;
}