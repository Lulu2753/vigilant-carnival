#include <stdio.h>

int main()
{
	char ch=0;

	for (; ch != '0';)
	{
		ch = getchar();    //如果这个放在第一个分号前，则输入的第一个为ch的初始值，再按回车实际上又输入了一个字符即\n，所以退出循环（如果条件是不等于\n)；条件改成不等于别的就可以了，只是每次会自带一个10
		printf("%d\n", ch);   //10是\n的ASC2码
		//system("cls");
	}


	/*for (scanf_s("%c", &ch); ch != 0;scanf_s("%c", ch))
	{
		printf("%d\n", ch);
		system("cls");
		break;
	}*/

	return 0;
}