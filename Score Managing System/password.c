#include <stdio.h>
#include "functions.h"

void psw()
{
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
			if (c == '\r')
			{
				psw[i] = '\0';
				break;
			}

			else if (c == '\b')
			{
				printf("\b \b");
				i--;
			}

			else
			{
				psw[i] = c;
				printf("*");
				i++;
			}
		}

		if (strcmp(admin.password, psw) != 0)
			printf("\nError!Please try again!\n");


	} while (strcmp(admin.name, user) != 0 || strcmp(admin.password, psw) != 0);

	printf("\nWelcome! %s\n", user);

}