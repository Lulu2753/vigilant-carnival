#include <stdio.h>
#define MAXLINE 1000

void reverseAns(char s[]);
void reverse2(char s[]);
int getline(char s[], int lim);

int main()
{
    char line[MAXLINE];

    while(getline(line, MAXLINE) > 0)
    {
        reverse(line);
    }

}

void reverseAns(char s[])
{
    char tempt;

    int i, j;
    i = 0;

    while(s[i] != '\0')
        ++i;   //\0是第i个，要去除
    --i;

    if(s[i] == '\n')
        --i;

    j = 0;
    while(j < i)
    {
        tempt = s[i];
        s[i] = s[j];
        s[j] = tempt;
        --i;
        ++j;
    }

    printf("%s", s);

}

void reverse2(char s[])
{
    char r[MAXLINE];

    int i, j;
    i = 0;
    j = 0;

    if (s[0] == '\0' || (s[0] == '\n' && s[1] == '\0'))
        return;

    while(s[i] != '\0')
        ++i;
    --i;

    if(s[i] == '\n')
        --i;

    r[i] = '\0';

    while(i >= 0)
    {
        r[i] = s[j];
        ++j;
        --i;
    }

    printf("%s",r);

}

int getline(char s[], int lim)
{
    int c, i, j;

    j = 0;

    for(i=0; (c=getchar())!=EOF && c!='\n' && i<lim-2; ++i)
    {
        s[j] = c;
        ++j;
        
    }

    if(c == '\n')
        {
            s[j] = '\n';
            ++i;
            ++j;
        }

    s[j] = '\0';
    return i;
}
