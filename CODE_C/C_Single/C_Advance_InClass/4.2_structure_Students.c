#include <stdio.h>

struct student // 类型名
{
    int num;
    float score;
};
/*找出成绩最好的并求和*/
void main()
{
    struct student stu, max;
    int i;
    float sum = 0;
    max.score = 0;

    for (i = 0; i < 5; i++)
    {
        scanf("%d%f", &stu.num, &stu.score);
        if (stu.score > max.score)
            max = stu;
        sum += stu.score;
    }

    printf("\nMax:%d-%.1f\n", max.num, max.score);
    printf("Sum:%.1f\n", sum);
}