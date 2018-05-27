#include <cstdio>
#include <map>

using std::map;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	map<int, int> dic;
	int ans = n, train[100001]{};
	while (m--)
	{
		int a, b, c;
		scanf("%d %d", &a, &b);

		if (a < 3) scanf("%d", &c);
		if (train[b] < 0) continue;

		if (a == 1) train[b] |= 1 << c - 1;
		else if (a == 2) train[b] &= ~(1 << c - 1);
		else if (a == 3) train[b] = (train[b] << 1) & (1 << 20) - 1;
		else train[b] >>= 1;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (dic[train[i]]) --ans;
		else dic[train[i]] = 1;
	}

	printf("%d", ans);

	return 0;
}