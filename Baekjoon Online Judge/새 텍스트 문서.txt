#include <cstdio>
#include <queue>
#include <tuple>

using std::queue;
using std::tuple;
using std::get;

typedef tuple<int, int, int> ti3;

int h, w;
char v[1000][1001];

bool isValid(int x, int y)
{
	return x >= 0 && x < h && y >= 0 && y < w;
}
int aroundCnt(int x, int y)
{
	int ret = 0;
	for (int i = -1; i <= 1; ++i)
		for (int j = -1; j <= 1; ++j)
			if (isValid(x + i, y + j) && v[x + i][y + j] == '.') ++ret;

	return ret;
}
int main()
{
	scanf("%d %d", &h, &w);

	queue<ti3> q;
	for (int i = 0; i < h; ++i) scanf("%s", v[i]);

	bool check[1000][1000]{};
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (aroundCnt(i, j) >= v[i][j] - 48)
			{
				q.push({ i, j, 1 });
				check[i][j] = true;
			}
	
	int cnt = 0;
	while (!q.empty())
	{
		auto pos = q.front();
		q.pop();

		int x = get<0>(pos);
		int y = get<1>(pos);
		cnt = get<2>(pos);

		v[x][y] = '.';

		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				int nx = x + i;
				int ny = y + j;

				if (!isValid(nx, ny) || check[nx][ny] ||
					v[nx][ny] == '.' || aroundCnt(nx, ny) < v[nx][ny] - 48) continue;

				check[nx][ny] = true;
				q.push({ nx, ny, cnt + 1 });
			}
		}
	}

	printf("%d", cnt);

	return 0;
}