#include <stdio.h>
#include <stdlib.h>

int main()
{
	char reply;

	do
	{
		system("cls");
		printf("A or B:");
		reply = getchar();  //getchar返回值为int，所以下面reply要打单引号表示其ASC2码

	} while (reply!='A' && reply!='B');  //while里面不能打引号

	printf("Correct!\n");

	return 0;
}