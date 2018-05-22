#include <cstdio>

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	int scores[100];
	for (int i = 0; i < n; ++i) scanf("%d", scores + i);

	int maxVal = 0, maxIdx = 100000, idx, val;
	char sc;
	for (int i = 0; i < m; ++i)
	{
		val = 0;
		scanf("%d", &idx);

		for (int j = 0; j < n; ++j)
		{
			scanf(" %c", &sc);
			val += (sc == 'O') * scores[j];
		}

		if (maxVal < val)
		{
			maxVal = val;
			maxIdx = idx;
		}
		else if (maxVal == val && maxIdx > idx) maxIdx = idx;
	}

	printf("%d %d", maxIdx, maxVal);

	return 0;
}