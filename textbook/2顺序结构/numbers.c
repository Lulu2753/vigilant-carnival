#include <stdio.h>

int main()
{
	printf("123456\b89\n");  // \b ��ʾ׼������8��ʱ�򣬹����ǰŲһ�񣬸��Ǻ���Ľ�������
	printf("123456\b\b\b89\n");


	printf("\101 \x42 C\n");

	printf("'\101'\n");   //���ϵ����������ASC2�������ַ������Ҳ��ʾ������

	printf("I say :\"How are you?\"\n");
	printf("\\C Program\\ \n");
	printf("Turbo \'C\'\n");

	return 0;
}