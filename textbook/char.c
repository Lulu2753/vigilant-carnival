#include <stdio.h>

int main()
{
	printf("a+3=%d\n", 'a' + 3);  //'' 单引号表示其ASC2码, 即char无条件横向转到int
	
	printf("%d\n", 5 / 2);

	printf("%.2f,%.2f\n", 5.0 / 2, 2 * 2.5);
	
	printf("%d,%d\n", 10 % 3,'C'%5);

	printf("%d,%f,%f\n", 3 / 5, 3.0 / 5, 3 / 5.0); //不同类型会转换成同一类型，除以一定要是float
	
	
	return 0;
}