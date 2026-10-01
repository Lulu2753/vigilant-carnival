#include <stdio.h>

/*统计成绩并排序8门课*/

struct student
{
    char name[20];
    float score;
};

void main()
{
    struct student stu[3] = {{"Li Hong", 0}, {"Wang Jian", 0}, {"Zhao Ming", 0}};
    struct student temp;
    int i, j;
    float x;

    for (i = 1; i <= 8; i++)
    {
        printf("\nInput the %dth course score:\n", i);
        for (j = 0; j < 3; j++)
        {
            printf("Name:%-12sScore:", stu[j].name);
            scanf("%f", &x);
            stu[j].score += x;
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++) // 从下一个开始与前一个开始比较
        {
            if (stu[i].score < stu[j].score)
            {
                temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }

    for (i = 0; i < 3; i++)
        printf("\nName:%-15sScore:%.1f", stu[i].name, stu[i].score);
}