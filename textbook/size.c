#include <stdio.h>

int main()
{
	
	printf("%d byte\n", sizeof(""));  //ֱ����sizeof���������������ַ����������ǿմ�

	printf("Hello\
 world\n");     //ֻ���ڴ����Ϸ��У������û���У��ո�ʵ�ʵ���

	printf("Hello\n" 
		     "\0world and you\n");  //�������Ÿ�������ڴ�����������У�������Ĳ����У�Ҳû�ո�������ַ�\0����������ȫ������,���������\n

	printf("Hello"
		" world\n");  //�ո�������漴�ɿո�
	return 0;
}