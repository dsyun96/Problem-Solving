#include <cstdio>
#include <vector>
#include <cstring>

using std::vector;

int parent(vector<vector<int>> &r, int *hst, int idx, int v, int &h)
{
	for (auto &it : r[idx])
	{
		if (hst[it] >= v) continue;

		hst[it] = h++;
		return parent(r, hst, it, v, h);
	}

	return idx;
}
void fill(vector<vector<int>> &r, int *hst, int idx)
{
	if (hst[idx] == -1) return;

	hst[idx] = -1;
	for (auto &it : r[idx])
		fill(r, hst, it);
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	vector<vector<int>> wif(n), go(n);
	int *hst = new int[n];
	int a, b;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &a, &b);
		wif[b].push_back(a);
		go[a].push_back(b);
	}

	memset(hst, 0, sizeof(int) * n);

	int pa, h = 1, cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (hst[i] < 0) continue;
		pa = parent(wif, hst, i, h, h);

		fill(go, hst, pa);
		++cnt;
	}

	printf("%d", cnt);

	delete[] hst;

	return 0;
}