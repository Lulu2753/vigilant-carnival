#include <stdio.h>

int main()
{
    char name[][80] = {"aa", "bbb", "c", "ddd", "eeee"}; // 5行80列
    char *pname[10], i;

    for (i = 0; i < 5; i++)
        pname[i] = name[i]; // 表示第i行的首地址，赋值的地址
    for (i = 0; i < 5; i++)
        puts(pname[i]); // 打印是从首地址开始打印直到遇到'\0'为止，printf也是

    char *qname[10] = {"aa", "bbb", "c", "ddd", "eeee"};
    int i;
    for (i = 0; i < 5; i++)
        puts(qname[i]);

    return 0;
}