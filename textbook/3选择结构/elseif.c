#include <stdio.h>

int main()
{
	char grade;
	scanf_s("%c", &grade);
	if (grade == 'A')
		printf("85~100");
	else if (grade == 'B')  //if加一堆else if，很多个if结构不明朗，因为有可能是嵌套关系
		printf("70~84");
	else if (grade == 'C')
		printf("60~69");
	else if (grade == 'D')
		printf("Failed");
	else
		printf("Error");

	return 0;
	
}