#include <stdio.h>
#include <conio.h>
int main()
{
	char c1, c2;
	printf("char=");
	c1 = getchar();//����
	_putch(c1);     //��c1ֵ�����screen����conio������ģ���ͬ��putchar()������ַ�����
	printf("%4d\n", c1);  //���ASC2��
	c2 = c1 + 32;
	putchar(c2);
	printf("%4d\n", c2);  //%4d��ʾ��߲���ո���4λ

	/*
	����A���ǶԵģ�����a��_putch��putchar��������ͬ��ǰ��-127�����ߣ�127����û�пո�
	*/


	return 0;
}