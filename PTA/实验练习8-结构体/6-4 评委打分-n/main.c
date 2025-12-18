#include<stdio.h>
struct Score {
    int id;
    char name[20];
    int score[17];
    float total;
    int rank; //成员包括学生编号、姓名、评分、总成绩、排名

};

void GetScore( struct Score grade[], int n );
void CalcuScore(struct Score grade[], int n);
void Ranking(struct Score grade[], int n);
void PrintScore(struct Score grade[], int n);

int main()
{
    int n;
    scanf("%d", &n); //确定参加的选手人数
    struct Score grade[20];
    GetScore(grade, n);
    CalcuScore(grade, n);
    Ranking(grade, n);
    PrintScore(grade, n);
    return 0;
}


void GetScore( struct Score grade[], int n )
{
    for(int i=0;i<n;i++)
    {
        scanf("%d%s",&grade[i].id,&grade[i].name);
        for(int j=0;j<17;j++)
            scanf("%d",&grade[i].score[j]);
    }
}
void CalcuScore(struct Score grade[], int n)
{


    for(int i=0;i<n;i++)
    {
        int max=0,min=100;

        grade[i].total=0;

        for(int j=0;j<17;j++)
        {
            grade[i].total+=grade[i].score[j];

            if(grade[i].score[j]>max)
                max=grade[i].score[j];

            if(grade[i].score[j]<min)
                min=grade[i].score[j];
        }

        grade[i].total=(grade[i].total-max-min)/15.0;
    }

}
void Ranking(struct Score grade[], int n)     //排序
{

    /*for(int i=0;i<n;i++)
    {
        grade[i].rank=n;

        for(int j=0;j<n&&j!=i;j++)
        {
            if(grade[i].total>grade[j].total)
                grade[i].rank--;

        }

    }*/

     for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(grade[j].total < grade[j + 1].total)
            {
                // 交换结构体
                struct Score temp = grade[j];
                grade[j] = grade[j + 1];
                grade[j + 1] = temp;
            }
        }
    }


         for(int i = 0; i < n; i++)
    {
        if(i == 0)
        {
            grade[i].rank = 1;
        }
        else
        {
            // 如果总分相同，则排名相同
            if(grade[i].total == grade[i - 1].total)
                grade[i].rank = grade[i - 1].rank;
            else
                grade[i].rank = i + 1;
        }
    }

}
void PrintScore(struct Score grade[], int n)
{

    for(int i=0;i<n;i++)
    {
        /*if(grade[i].rank==i-1)
            printf("第%d名 %d %s  %.2f\n",grade[i].rank,grade[i].id,grade[i].name,grade[i].total);
    */

    printf("第%d名 %d %s %.2f\n",
               grade[i].rank,
               grade[i].id,
               grade[i].name,
               grade[i].total);

    }
}
