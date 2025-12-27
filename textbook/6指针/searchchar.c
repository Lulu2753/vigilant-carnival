#include <stdio.h>
#include <string.h>

char* s(char* st, char m) //传递字符串地址，这样相当于可以找到对应的
{
	while (*st != m && *st != 0)
		st++;
	if (*st == m)
		return st; //st是传过来的地址，现在要返回回去，返回的是地址值（很大的数），所以函数设置为指针！
	else
		return NULL;
}

int main()
{
	char str[100], x;

	x = getchar();
	getchar();     //吸收换行


	gets(str);

	if (s(str, x) != NULL)
		printf("found %c in %s\n", x, s(str, x));//可以直接打印这个函数，因为返回值是指针，所以打印首地址往后的串！但这个函数要完整
	else
		printf("Not found!\n");       /*printf("%s",*str)这样会发生段错误，传递的是第一个字符的ASCII码，传入的char，于string不符合*/

	return 0;

}