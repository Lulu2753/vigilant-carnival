#include <stdio.h>

int main()
{
	int i = 3, x;
	x = i++;
	printf("%d\n", x);//�Ȱ�i=3��ֵ����x��Ȼ��i�Լ��ټ�1����ʱi=4
	x = ++i;  //��ʱ��i�Լ��ټ�1����i=5���ٰ�5����x
	printf("%d,%d\n", x, i);


	int m, n = 10;
	++n; //ֱ��д�����û�и�ֵ����Ҳ��ʾn�Լ���1��n++Ҳһ����Ч������Ϊû�а�n��ֵ��˭
	printf("%d\n", n);

	return 0;
}