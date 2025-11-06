#include <stdio.h>
#include <math.h>

int main()
{
	int price,salary,hour;
	scanf_s("%d", &price);

	hour =ceil( (price - 3200) *1.0/ 40);


		if (price <= 3200)
			printf("不需加班，可购买");

		else if (3200 < price && price <= 4800)
			printf("需加班%d小时,可购买", hour);

		else if (price > 4800)
			printf("需加班%d小时,买不起", hour);

		return 0;


}