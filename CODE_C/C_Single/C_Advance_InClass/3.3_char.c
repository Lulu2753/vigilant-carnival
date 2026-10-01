#include <stdio.h>

int main()
{
    char s[] = "Hello, World!", *p;
    p = s; // p指向s的首地址，指针指向首地址，传递字符串
    puts(p);
    p = "Hello, C!";
    puts(p);

    return 0;
}

void main()
{
    char *p;             // 定义指针
    p = "Hello, World!"; // p指向无名数组，同样合法
    puts(p);
    p = "Hello, C!";
    puts(p);
}

/*先定义char s[10]， 再s="hello!"不行，要在定义的时候就初始化
定义char *ps；ps="hello!"，可以
不可以scanf("%s",ps)，因为ps没有指向具体的数组
可以char *ps，s[10],ps=s,scanf可以，因为有一个具体指向可以存到的地方
可以写作ps[9]，但不能越界写成ps[10]*/