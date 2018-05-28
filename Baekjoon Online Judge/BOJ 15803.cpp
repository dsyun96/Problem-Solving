#include <cstdio>

int main()
{
	int a[6];
	for (int i = 0; i < 6; ++i) scanf("%d", a + i);

	if ((a[0] - a[2]) * (a[3] - a[5]) == (a[2] - a[4]) * (a[1] - a[3])) puts("WHERE IS MY CHICKEN?");
	else puts("WINNER WINNER CHICKEN DINNER!");

	return 0;
}