#include <stdio.h>

int main()
{
	float x;
	int y;
	printf("x=");
	scanf_s("%f", &x);
	if (x >= 0)
		y = 1;
	if (x < 0)
		y = -1;

	printf("%.0f,%d\n", x, y);  //%g����ֻ������Ч����,%.0f�������������뵽�����������ط��������Ϊ0

	
	if (x - (int)x == 0)    //ǿ������ת�������int����float�����ţ������Ǵ�����ȥ
		printf("%.0f,%d\n", x, y);
	if (x - (int)x != 0)
		printf("%g,%d\n", x, y);

	return 0;

}
