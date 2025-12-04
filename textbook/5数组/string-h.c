#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	char str[12] = "How are you";

	printf("%d\n", strlen(str));  //输出长度，不包括最后的\0，手动在you后面加\0也是11

	char str1[12] = "World", str2[6] = " Cup";


	strcat_s(str1, sizeof(str1), str2);  //可以理解为不停的把字符串连接到str1上
	printf("%s\n",str1);   //strcat_s(dest, sizeof(dest), src);

	/*正常是这样printf("%s", strcat(str1,str2) );*/

	char s[10];
	strcpy_s(s, sizeof(s),"Beijing");//相当于起到【赋值】的作用，但不能s[10]=“beijing”这样直接赋值，这只能在最开始定义的时候这么赋值
	puts(s);
	strcpy_s(s, sizeof(s),"Wuhan");
	puts(s);    //puts遇到\0即截止，所以不会输出g，所有print类的都不会跳过中间的\0

	/*交换顺序同理，要介入t*/

	printf("%d\n", strcmp("abcd", "ABcd"));   //'a'>'A'
	printf("%d\n", strcmp("ABCD", "AbCD"));
	printf("%d\n", strcmp("pencil", "pen"));

	/*判断字符串是否相等得用【if(strcmp(a,b)==0)】，否则a==b看的是首地址是否一样，实数得用fabs(a-b)<1e-6，因为会有精度问题，整数直接a=b*/


	
		
	return 0;
}