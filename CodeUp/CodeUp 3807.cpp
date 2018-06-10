#include <cstdio>

int main()
{
	int m, n;
	scanf("%d %d", &m, &n);

	int arr[100];
	for (int i = 0; i < m; ++i) scanf("%d", arr + i);

	int dp[10001] = { 1 };
	for (int i = 0; i < m; ++i)
		for (int j = 1; j <= n; ++j) if (arr[i] <= j)
			dp[j] += dp[j - arr[i]];

	printf("%d", dp[n]);

	return 0;
}