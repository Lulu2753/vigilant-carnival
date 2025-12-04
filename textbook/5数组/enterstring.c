#include <stdio.h>


int main()
{
	char name[15];

	scanf_s("%s", name,14); //scanf_s必须要指定长度范围，输入最多是15-1，因为最后回车表示\0，name表示字符数组首地址

	

	printf("1. 整个字符串: %s\n", name);        // 若输入Hello  //传递的是首地址给printf %s，！！！printf找到首地址，依次输出直到\0
	printf("2. 数组名值（地址）: %p\n", name);   // 0x...（地址）   //%p表示输出地址，十六进制
	printf("3. 首地址值: %p\n", &name[0]);      // 与上面相同
	printf("4. 第一个字符: %c\n", name[0]);     // H
	printf("5. 解引用: %c\n", *name);           // H  //解引用：返回内存地址中对应的对象，即*
	printf("6. 第二个字符: %c\n", *(name + 1)); // e

	return 0;
}