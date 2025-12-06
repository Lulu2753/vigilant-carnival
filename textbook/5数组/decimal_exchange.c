#include <stdio.h>
#include <math.h>

int main()
{
	int  i, m = 0, flag = 0;  //放在for里面效果一样，但最好初始化
	char n[16];


	scanf_s("%s", n, 15);



	for (i = 0; i < strlen(n); i++)
	{
	
		
		if (n[i] != '0' && n[i] != '1') //形式是字符串，字符，所以得单引号！！！！
		{
			printf("ERROR!");
			flag = 1;
			break;
			
		}

		m += pow(2, strlen(n)-1 - i) * (n[i] - '0');   //以实际长度为界
	}

	if(flag==0)
		printf("%d", m);

	return 0;
}