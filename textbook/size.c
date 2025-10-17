#include <stdio.h>

int main()
{
	
	printf("%d byte\n", sizeof(""));  //直接在sizeof括号里输入待求的字符串，这里是空串

	printf("Hello\
 world\n");     //只是在代码上分行，输出的没分行，空格按实际的来

	printf("Hello\n" 
		     "\0world and you\n");  //两个引号隔开则可在代码区随意分行，但输出的不分行，也没空格，引入空字符\0这个引号里的全作废了,包括里面的\n

	printf("Hello"
		" world\n");  //空格放在里面即可空格
	return 0;
}