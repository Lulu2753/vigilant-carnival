#include <stdio.h>
#define A "I am"
#define B "a student."  //�����ַ���������˫���ţ�������Ȧ���������ַ��ͳ����������ASC2ֵ
#define SPACE " "
#define C A SPACE B  //�����ʱ���м�ӿո�û�ã������пո�

int main()
{
	printf("%s\n",A SPACE B);   //%s�����ַ���������֮��ֻ�ܿո񣬼Ӷ�����ֻ����ʾ��һ�Զ����ڵ�
	printf("%s\n",C);

	return 0;
}