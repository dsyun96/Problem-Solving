#include <cstdio>
#include <set>

using std::set;

int main()
{
	const int dx[] = { -1, 0, 0, 1 };
	const int dy[] = { 0, -1, 1, 0 };
	int r, c;
	scanf("%d %d", &r, &c);

	char v[50][51];
	for (int i = 0; i < r; ++i) scanf(" %s", v[i]);

	set<int> s, a;
	int dest;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			if (v[i][j] == 'S') s.insert(i * 100 + j);
			else if (v[i][j] == '*') a.insert(i * 100 + j);
			else if (v[i][j] == 'D') dest = i * 100 + j;
		}

	int cnt = 0;
	while (!s.empty())
	{
		set<int> ts, ta;

		for (int it : s)
		{
			int x = it / 100;
			int y = it % 100;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx * 100 + ny == dest) return printf("%d", cnt + 1) * 0;
				if (nx < 0 || nx >= r || ny < 0 || ny >= c || v[nx][ny] != '.') continue;

				ts.insert(nx * 100 + ny);
				v[nx][ny] = 'S';
			}
		}

		for (int it : a)
		{
			int x = it / 100;
			int y = it % 100;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c ||
					v[nx][ny] != 'S' && v[nx][ny] != '.') continue;

				ts.erase(nx * 100 + ny);
				ta.insert(nx * 100 + ny);
				v[nx][ny] = '*';
			}
		}

		s = ts;
		a = ta;
		++cnt;
	}

	printf("KAKTUS");

	return 0;
}