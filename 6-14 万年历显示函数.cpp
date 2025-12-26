#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>  //有getch等，还有textcolor(),textnackground()
#include <graphics.h>  //画图用

int IsLeapYear(int y);   /*判断是否闰年，细节不表*/
int GetDaysofMonth(int y, int m); /*确定某个月的天数，细节不表*/
int GetTotalDays(int y, int m); /*计算从1900年1月开始到给定年月间的天数，不包含给定月的天数，细节不表*/
int GetFirstDayInTable(int y, int m); /*计算给定年月的第一天在日历表中的位置，返回值为0对应Sun位置，返回值为6对应Sta位置，细节不表*/
void ShowDate(int y, int m); /*显示日历*/

void textcolor(int color);

int main()
{
    int y, m;

    while (1)
    {
        scanf_s("%d%d", &y, &m);

        if (y < 1900 || m <= 0 || m>12)
        {
            printf("\nError! Please enter the right year and month!\n\n");
            system("pause");
            system("cls");
        }

        else
            break;
    }
    
    printf("\n");

    ShowDate(y, m);

    printf("\n");
    system("pause");
    return 0;
}

int IsLeapYear(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        return 1;
    return 0;
}

int GetDaysofMonth(int y, int m)
{
    int days[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (m == 2 && IsLeapYear(y)) return 29;
    return days[m - 1];   //直接数组简洁表示

    /*if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        return 30;
    else
    {
        if (IsLeapYear(y) == 1)
            return 29;
        else
            return 28;
    }*/

}

int GetTotalDays(int y, int m)
{
    int i, total = 0;

    for (i = 1900; i < y; i++)
        total += 365 + IsLeapYear(i);

    for (i = 1; i < m; i++)
        total += GetDaysofMonth(y, i);

    return total;
    
}

int GetFirstDayInTable(int y, int m)
{
    int x;
    x = GetTotalDays(y, m) % 7;
    
    return x+1;
}


void ShowDate(int y, int m)
{ 
    int i, j, k, count=0;

    for (i = 0; i < 35; i++)
    {
        //textcolor(RED);
        printf("*");
    }
    printf("\n");

    printf("  Sun  Mon Tues  Wed Thur  Fri  Sat\n");

    for (k = 0; k < GetFirstDayInTable(y, m); k++)  //调用就不要加int
    {
        printf("     ");
        count++;
    }

    for (i = 1; i <= GetDaysofMonth(y, m); i++)
    {
        printf("%5d", i);
        count++;

        if (count % 7 == 0)
            printf("\n");
    }
    printf("\n");

    for (i = 0; i < 35; i++)
        printf("*");
    printf("\n");

}
