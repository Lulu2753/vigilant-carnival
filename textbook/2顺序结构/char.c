#include <stdio.h>

int main()
{
	printf("a+3=%d\n", 'a' + 3);  //'' �����ű�ʾ��ASC2��, ��char����������ת��int
	
	printf("%d\n", 5 / 2);

	printf("%.2f,%.2f\n", 5.0 / 2, 2 * 2.5);
	
	printf("%d,%d\n", 10 % 3,'C'%5);

	printf("%d,%f,%f\n", 3 / 5, 3.0 / 5, 3 / 5.0); //��ͬ���ͻ�ת����ͬһ���ͣ�����һ��Ҫ��float
	
	
	return 0;
}