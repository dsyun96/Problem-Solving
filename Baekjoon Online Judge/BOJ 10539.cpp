#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);

	int a[100], b[100];
	for (int i = 0; i < n; ++i) scanf("%d", b + i);

	for (int i = 0; i < n - 1; ++i)
		a[n - 1 - i] = b[n - 1 - i] * (n - i) - b[n - 2 - i] * (n - 1 - i);
	
	printf("%d", b[0]);
	for (int i = 1; i < n; ++i) printf(" %d", a[i]);

	return 0;
}