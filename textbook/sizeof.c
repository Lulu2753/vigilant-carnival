#include <stdio.h>

int main()
{
	char ab;
	
	printf("%zd\n", sizeof(ab));  //因为定义了char，就是一个字节，即使是两个字母（真的不知道为什么。。）
	
	printf("%zd\n", sizeof('a' + 12));   //单引号转换成int

	printf("%zd\n", sizeof 9.3);  //也可以不用括号

	/*
	
	%zd是VS自己提示的输入类型，因为是sizeof输出的

	主要问题是无法做到输入任意字符输出size，目前只能指定输入类型，然后输入数字输出size
	但这样无意义，指定类型的size都确定了
	更不能输入字符类型的字母比如char,int等，都会报错
	探索ing...
	
	
	*/




	return 0;
}