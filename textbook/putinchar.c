#include <stdio.h>

int main()
{
	char ch;
	ch = getchar();  //ר����������һ���ַ���������ĸ��תΪASC2�������ת��ȥ���
	ch = ch + 3;

	putchar(ch);   //���printf("%c\n", ch);ר���������һ���ַ�,��������������������Ϊ��ĸ��ch

	putchar('\n');//������һ�����������,��ֱ�Ӽ���chһ��

	putchar('A');

	return 0;
}