#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int v, cnt = 0;
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &v);
		cnt += -~v >> 1;
	}

	puts(cnt >= n ? "YES" : "NO");

	return 0;
}