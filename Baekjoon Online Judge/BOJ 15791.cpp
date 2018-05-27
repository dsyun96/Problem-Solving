#include <cstdio>
#define MOD 1000000007

int fastExp(int n, int r)
{
	int ret = 1;
	while (r)
	{
		if (r & 1) ret = 1l * ret * n % MOD;
		n = 1l * n * n % MOD;
		r >>= 1;
	}

	return ret;
}
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	if (k > n / 2) k = n - k;

	int a = 1, b = 1;
	for (int i = 0; i < k; ++i)
	{
		a = 1l * a * (n - i) % MOD;
		b = 1l * b * (k - i) % MOD;
	}

	b = fastExp(b, MOD - 2);
	printf("%d", 1l * a * b % MOD);

	return 0;
}