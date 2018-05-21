#include <cstdio>

inline int max(int a, int b) { return a > b ? a : b; }
int main()
{
	int c;
	scanf("%d", &c);

	int arr[100][100];
	while (c--)
	{
		int n;
		scanf("%d", &n);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= i; ++j)
				scanf("%d", arr[i] + j);

		int dp[100][100]{ 1 };
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0 || j == i)
				{
					arr[i][j] += arr[i - 1][j - (j == i)];
					dp[i][j] = dp[i - 1][j - (j == i)];
				}
				else
				{
					arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
					dp[i][j] = arr[i - 1][j] == arr[i - 1][j - 1] ?
						dp[i - 1][j] + dp[i - 1][j - 1] : arr[i - 1][j] > arr[i - 1][j - 1] ?
						dp[i - 1][j] : dp[i - 1][j - 1];
				}
			}
		}

		int ans = 0, val = 0;
		for (int i = 0; i < n; ++i)
		{
			if (arr[n - 1][i] > val)
			{
				val = arr[n - 1][i];
				ans = dp[n - 1][i];
			}
			else if (arr[n - 1][i] == val)
			{
				ans += dp[n - 1][i];
			}
		}

		printf("%d\n", ans);
	}

	return 0;
}