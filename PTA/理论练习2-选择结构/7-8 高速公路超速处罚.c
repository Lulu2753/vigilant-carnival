#include <stdio.h>

int main()
{
	int vfact, vlimit;
	float percentage=0;

	scanf_s("%d %d", &vfact, &vlimit);

	percentage = 100*(vfact - vlimit) * 1.0 / vlimit;

	if (percentage < 10)
		printf("OK");
	else if (10 <= percentage && percentage < 50)
		printf("Exceed %.0f%%. Ticket 200", percentage);
	else if (50 <= percentage)
		printf("Exceed %.0f%%. License Revoked", percentage);

	return 0;
}