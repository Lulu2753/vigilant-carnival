#include <stdio.h>

int main()
{
	int m = 1;long p = 4l; float f = 1.0; //l���д��ʾlong������
	//����Ҳ���Է���д
	
	double s;
	s = 'a' + 11 * m % 2 + f - p;  //%���ȼ��ڳ˳�֮��������Ϊ������ȼ����Ӽ���������ȼ�
	printf("%f", s);

	return 0;


}