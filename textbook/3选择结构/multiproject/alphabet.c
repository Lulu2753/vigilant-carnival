#include <stdio.h>
#include "file.h"  //�Լ������ļ�Ҫ�����ţ�<>�Ǵӿ����ң��ŵ�ͷ�ļ�����

void main()  //void����return
{
	char ch;
	int max;
	double y;

	scanf_s("%c", &ch);
	ch = (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;  //��ֵ; ASC2����A��Z֮��
	printf("%c\n", ch);

	max =master1();
	printf("%d", max);

	y = abc123();
	printf("%g", y);

	max = day();

	printf("\n%d", max);
	//return 0;

	
}

