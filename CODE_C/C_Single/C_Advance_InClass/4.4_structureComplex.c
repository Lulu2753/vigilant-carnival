#include <stdio.h>
#define FORMAT "\nNo:%d\nName:%s\nScore1:%.1f\nScore2:%.1f%\nScore3:%.1f\n"
// 太长于是重新定义

struct student
{
    int num;
    char name[20];
    float score[3];
};

void output(struct student ps)
{
    printf(FORMAT, ps.num, ps.name, ps.score[0], ps.score[1], ps.score[2]);
}

void input(struct student *ps) // 必须指针传出去，才能让stu初始化，否则乱码
{
    printf("No:\tName:\tScore1:\tScore2:\tScore3:\n");

    scanf("%d", &(*ps).num);    //.的优先级大于*
    scanf("%s", &ps->name);     // 两种写法，指针必须先解引用，才能访问结构体成员
    scanf("%f", &ps->score[0]); // 箭头是直接访问
    scanf("%f", &ps->score[1]);
    scanf("%f", &ps->score[2]);
}
void main()
{
    struct student stu;

    input(&stu);
    output(stu); // 传递形参
}