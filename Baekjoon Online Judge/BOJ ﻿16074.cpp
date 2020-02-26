#include <bits/stdc++.h>
#define X first
#define Y second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define ini(x, y) memset(x, y, sizeof(x))
#define endl '\n'
#define fastio cin.sync_with_stdio(false); cin.tie(nullptr)
using namespace std;

using ll = long long;
using pii = pair<int, int>;
const int MOD = 1e9 + 7;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int pa[250000];
int depth[250000];
vector<pii> lca[19];
vector<pii> adj[250000];

int fnd(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = fnd(pa[n]);
}
void uni(int a, int b) {
	a = fnd(a), b = fnd(b);
	if (a != b) pa[b] = a;
}
void dfs(int now, int prv) {
	for (auto[nxt, w] : adj[now]) if (nxt != prv) {
		lca[0][nxt] = { now, w };
		depth[nxt] = depth[now] + 1;
		dfs(nxt, now);
	}
}
int main() {
	fastio; ini(pa, -1);
	int m, n, q;
	cin >> m >> n >> q;

	int bo[500][500];
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			cin >> bo[i][j];

	vector<pair<int, pii>> edge;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			int a = i * n + j;
			for (int k = 0; k < 2; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny >= n) continue;

				int b = nx * n + ny;
				edge.emplace_back(max(bo[i][j], bo[nx][ny]), pii(a, b));
			}
		}
	}

	sort(all(edge));

	for (auto &it : edge) if (fnd(it.Y.X) != fnd(it.Y.Y)) {
		uni(it.Y.X, it.Y.Y);
		adj[it.Y.X].emplace_back(it.Y.Y, it.X);
		adj[it.Y.Y].emplace_back(it.Y.X, it.X);
	}

	int N = m * n;
	for (int i = 0; i < 19; ++i) lca[i].assign(N, pii(-1, -1));
	depth[0] = 0;
	dfs(0, -1);

	for (int j = 1; j < 19; ++j) for (int i = 0; i < N; ++i) {
		if (lca[j - 1][i].X == -1) continue;
		lca[j][i].X = lca[j - 1][lca[j - 1][i].X].X;
		lca[j][i].Y = max(lca[j - 1][i].Y, lca[j - 1][lca[j - 1][i].X].Y);
	}

	for (int x1, y1, x2, y2; q--; ) {
		cin >> x1 >> y1 >> x2 >> y2;
		--x1, --y1, --x2, --y2;
		int a = x1 * n + y1;
		int b = x2 * n + y2;

		if (depth[a] < depth[b]) swap(a, b);
		int dif = depth[a] - depth[b];

		int ans = max(bo[x1][y1], bo[x2][y2]);
		for (int i = 0; dif; ++i) {
			if (dif & 1) {
				ans = max(ans, lca[i][a].Y);
				a = lca[i][a].X;
			}
			dif >>= 1;
		}

		if (a != b) {
			for (int i = 19; i--; ) {
				if (lca[i][a].X != -1 && lca[i][a].X != lca[i][b].X) {
					ans = max(ans, lca[i][a].Y);
					ans = max(ans, lca[i][b].Y);
					a = lca[i][a].X;
					b = lca[i][b].X;
				}
			}
			ans = max(ans, lca[0][a].Y);
			ans = max(ans, lca[0][b].Y);
		}

		cout << ans << endl;
	}

	return 0;
}
