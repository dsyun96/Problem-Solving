#include <cstdio>

int C[201][201];

int findC(int a, int b)
{
	int &ret = C[a][b];
	if (ret) return ret;
	if (b == 0 || a == b) return ret = 1;
	if (b == 1) return ret = a;

	ret = findC(a - 1, b) + findC(a - 1, b - 1);

	if (ret > 1000000000) return ret = 1000000001;
	else return ret;
}
int main()
{
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	char ans[205]{};
	int idx = 0;

	int tn = n, tm = m;
	for (int i = 0; i < n + m; ++i)
	{
		if (tn == 0) ans[idx++] = 'z', --tm;
		else if (tm == 0) ans[idx++] = 'a', --tn;
		else if (findC(tn + tm - 1, tn - 1) < k)
		{
			ans[idx++] = 'z';
			k -= findC(tn + tm - 1, tn - 1);
			--tm;
		}
		else
		{
			ans[idx++] = 'a';
			--tn;
		}
	}

	if (k == 1) printf("%s", ans);
	else printf("-1");

	return 0;
}