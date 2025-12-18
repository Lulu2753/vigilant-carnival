#include<stdio.h>

struct product {
    int id;
    char name[20];
    double price;
};

void menu(struct product p[],int n);
void order(struct product p[],int n);

int main()
{
    struct product p[20];   // 最多可有50个商品
    int n;
    scanf("%d",&n);        // 商品数量
    for(int i=0; i<n; i++) {
        scanf("%d %s %lf",&p[i].id,p[i].name,&p[i].price);  // 输入各商品的编号、名称和单价
    }

    menu(p,n);     // 显示菜单
    order(p,n);    // 点单，输入所需商品，并按要求输出各商品的名称、数量及价格，以及最终的总价格

    return 0;
}

void menu(struct product p[],int n)
{
    for(int i=0;i<n;i++)

        printf("[%d] %s %.1lf\n",p[i].id,p[i].name,p[i].price);

}

void order(struct product p[],int n)
{
    int id,num,count[50]={0};
    double sum=0;

    while(1)
    {
        scanf("%d%d",&id,&num);

        if(id==0)
            break;

        for(int i=0;i<n;i++)
        {

            if(id==p[i].id)

            {
                count[i]+=num;
            }

        }

    }

    for(int i=0;i<n;i++)
    {
        if(count[i]!=0)
        {
            printf("%s * %d = %.1lf\n",p[i].name,count[i],count[i]*p[i].price);
            sum+=count[i]*p[i].price;

        }
    }


    printf("Total = %.1lf",sum);




}
