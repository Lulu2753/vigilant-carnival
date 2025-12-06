#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
	char name[] = "admin", password[] = "1234";
	char user[100], psw[100], c;
	
	
	do
	{
		printf("Please enter your username: ");
		gets(user);
		printf("Please enter your password: ");

		int i = 0;
		while (1)
		{
			c = _getch();
			if (c == '\r')//\r表示回车，\n表示换行，不一样！
			{
				psw[i] = '\0'; //逐个赋值的时候要加\0,因为比较是到最后\0
				break;
			}
				
			else if (c == '\b')
			{
				printf("\b \b");    //用空格覆盖星号,否则退格只是移到星号前面
				i--;
			}
			else
			{
				psw[i] = c;
				printf("*");
				i++;
			}
		}

		if (strcmp(name, user) != 0 || strcmp(password, psw) != 0)
			printf("\nError! Please try again.\n");

	} while (strcmp(name, user) != 0 || strcmp(password, psw) != 0);   //满足这个条件继续循环
	
	printf("\nWelcome! %s\n",user);

	return 0;

}