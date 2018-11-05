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

char bo[3][4];

int turn() {
	int x = 0, o = 0;
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			if (bo[i][j] == 'o') ++o;
			else if (bo[i][j] == 'x') ++x;

	return x > o; //1이면 o가 할 차례, 0이면 x가 할 차례
}
int isEnd() {
	bool finish = 1;
	int lx, lo, rx, ro;
	lx = lo = rx = ro = 0;
	for (int i = 0; i < 3; ++i) {
		int x = 0, o = 0;
		int xx = 0, oo = 0;
		for (int j = 0; j < 3; ++j) {
			if (bo[i][j] == '.') finish = 0;
			if (bo[i][j] == 'x') ++x;
			if (bo[i][j] == 'o') ++o;
			if (bo[j][i] == 'x') ++xx;
			if (bo[j][i] == 'o') ++oo;
		}

		if (x == 3 || xx == 3) return 1;
		if (o == 3 || oo == 3) return 0;

		if (bo[i][i] == 'x') ++lx;
		if (bo[i][i] == 'o') ++lo;
		if (bo[i][2 - i] == 'x') ++rx;
		if (bo[i][2 - i] == 'o') ++ro;
	}

	if (lx == 3 || rx == 3) return 1;
	if (lo == 3 || ro == 3) return 0;
	if (finish) return -1;

	return -2;
}
int check() {
	int e = isEnd();
	if (e == 0) return 1; //1이면 o가 이김
	if (e == 1) return 0; //0이면 x가 이김
	if (e == -1) return -1;

	int player = turn();
	bool f = player;
	int k = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (bo[i][j] != '.') continue;

			bo[i][j] = "xo"[player];
			int t = check();
			bo[i][j] = '.';

			if (t == f) return f;
			else if (t == -1) k = 1;
		}
	}

	if (k) return -1;
	else return player ^ 1;
}
int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		for (int i = 0; i < 3; ++i) scanf("%s", bo[i]);
		
		int r = check();
		puts(r < 0 ? "TIE" : r ? "o" : "x");
	}

	return 0;
}
