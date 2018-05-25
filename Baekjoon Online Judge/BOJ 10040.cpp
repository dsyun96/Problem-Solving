#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int A[1000];
	for (int i = 0; i < n; ++i) scanf("%d", A + i);

	int B[1000];
	for (int i = 0; i < m; ++i) scanf("%d", B + i);

	int idx, max = 0, R[1000]{};
	for (int i = 0; i < m; ++i)
	{
		int j;
		for (j = 0; B[i] < A[j]; ++j);

		if (max < ++R[j]) max = R[j], idx = j;
	}

	printf("%d", idx + 1);

	return 0;
}