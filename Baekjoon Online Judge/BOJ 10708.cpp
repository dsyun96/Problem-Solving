#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int A[101];
	for (int i = 1; i <= m; ++i) scanf("%d", A + i);

	int B[101]{};
	for (int i = 1; i <= m; ++i)
	{
		int v;

		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &v);
			if (j == A[i] || v == A[i]) B[j]++;
			else B[A[i]]++;
		}
	}

	for (int i = 1; i <= n; ++i)
		printf("%d\n", B[i]);

	return 0;
}