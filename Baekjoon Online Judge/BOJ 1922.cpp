#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <tuple>
#include <numeric>
#include <functional>
#include <algorithm>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const int MAX = 2e5 + 5;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int pa[1001];

int fnd(int n) {
	if (pa[n] < 0) return n;
	return pa[n] = fnd(pa[n]);
}
void uni(int a, int b) {
	a = fnd(a);
	b = fnd(b);
	if (a == b) return;
	pa[b] = a;
}
int main()
{
	memset(pa, -1, sizeof pa);

	int n, m;
	scanf("%d %d", &n, &m);

	vector<pair<int, pii>> vec(m);
	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		vec[i] = { c, { a, b } };
	}

	sort(all(vec));

	int ans = 0;
	for (auto &it : vec) {
		if (fnd(it.Y.X) == fnd(it.Y.Y)) continue;
		ans += it.X;
		uni(it.Y.X, it.Y.Y);
	}

	printf("%d", ans);

	return 0;
}
