#include <cstdio>

int main()
{
	int n, m, v;
	scanf("%d %d", &n, &m);

	long long res = 1;
	while (n--)
	{
		scanf("%d", &v);
		res = res * v % m;
	}

	printf("%lld", res);

	return 0;
}