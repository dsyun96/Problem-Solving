#include <cstdio>

int main()
{
	int n, m, v;
	scanf("%d %d", &n, &m);

	int maxh = 0, maxj = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);
		maxh = maxh < v ? v : maxh;
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &v);
		maxj = maxj < v ? v : maxj;
	}

	printf("%d", maxh + maxj);

	return 0;
}