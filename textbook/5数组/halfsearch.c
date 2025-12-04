#include <stdio.h>
#define n 9   //赋值可以随时在这里改，一次即可

/*二分法查找特定的一个数，前提是数列单调*/

int main()
{
	int a[n] = { 1,3,4,8,10,39,58,78,90 };

	int low=0, high=n-1, mid, key;
	
	scanf_s("%d", &key);

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (a[mid] == key)
			break;
		if (a[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;


	}

	if (low <= high) 
		printf("%d is found at %d.", key, mid);
	else
		printf("%d is not found.", key);
	
	return 0;
}