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
typedef pair<int, pii> T;

const int MOD = 123456789;
const int INF = 0x3f3f3f3f;
const int MAX = 100005;
const int dx[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };

int pa[500];

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
int dist(int x, int y) {
	int ret = 0;
	for (int i = 0; i < 4; ++i) {
		int tmp = (x % 10 - y % 10 + 10) % 10;
		if (tmp > 5) tmp = 10 - tmp;

		ret += tmp;
		x /= 10;
		y /= 10;
	}
	return ret;
}
int main()
{
	int t;
	scanf("%d", &t);

	while (t--) {
		memset(pa, -1, sizeof(pa));

		int n;
		scanf("%d", &n);

		int arr[500];
		for (int i = 0; i < n; ++i) scanf("%d", arr + i);

		vector<T> vec;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				vec.push_back({ dist(arr[i], arr[j]), {i, j} });
			}
		}

		sort(all(vec));

		int ans = 0;
		for (int i = 0; i < sz(vec); ++i) {
			int x = vec[i].Y.X;
			int y = vec[i].Y.Y;

			if (fnd(x) == fnd(y)) continue;
			ans += vec[i].X;
			uni(x, y);
		}

		int mn = dist(0, arr[0]);
		for (int i = 1; i < n; ++i) {
			mn = min(mn, dist(0, arr[i]));
		}

		printf("%d\n", ans + mn);
	}

	return 0;
}
