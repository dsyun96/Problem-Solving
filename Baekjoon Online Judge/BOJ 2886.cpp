#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
#define X first
#define Y second

typedef std::pair<int, int> pii;

int r, c, si, pi;
char board[101][101];
pii seat[10000];
pii pers[10000];

std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pqDist;

int main()
{
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; ++i) scanf("%s", board[i]);

	for (int i = 0; board[i][0]; ++i)
		for (int j = 0; board[i][j]; ++j)
		{
			if (board[i][j] == 'L') seat[si].X = i, seat[si++].Y = j;
			else if (board[i][j] == 'X') pers[pi].X = i, pers[pi++].Y = j;
		}

	for (int i = 0; i < pi; ++i)
	{
		int px = pers[i].X;
		int py = pers[i].Y;

		for (int j = 0; j < si; ++j)
		{
			int sx = seat[j].X;
			int sy = seat[j].Y;
			int dist = (px - sx) * (px - sx) + (py - sy) * (py - sy);

			pqDist.push({ dist, i * 10000 + j });
		}
	}

	int cnt = 0;
	while (!pqDist.empty())
	{
		auto v = pqDist.top();
		pqDist.pop();

		int pidx = v.Y / 10000;
		int sidx = v.Y % 10000;

		if (pers[pidx].X < 0) continue;
		if (seat[sidx].X < 0)
		{
			if (seat[sidx].X == -v.X)
			{
				++cnt;
				pers[pidx].X = -1;
				seat[sidx].X = -987654321;
			}
			continue;
		}

		pers[pidx].X = -1;
		seat[sidx].X = -v.X;
	}

	printf("%d", cnt);

	return 0;
}