#include <stdio.h>

struct student
{
    char name[20];
    int age;
    float score;
    struct student *next; // 指向下一个，链表，星号不能去掉
};

int main()
{
    printf("%ld", sizeof(long));

    return 0;
}
