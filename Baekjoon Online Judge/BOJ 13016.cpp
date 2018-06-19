#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
typedef tuple<int, int, vector<int>> tiiv;

vector<int> subLen, tmp;

pii bfs(vector<pii> (&v)[50001], int begin)
{
	queue<pii> q;
	q.push({begin, 0});
	
	int max = 0, node = 0;
	bool hst[50001]{};
	hst[begin] = 1;
	while (!q.empty())
	{
		auto val = q.front();
		q.pop();
		
		if (max < val.second)
		{
			max = val.second;
			node = val.first;
		}
		
		for (auto &it : v[val.first])
		{
			if (hst[it.first]) continue;
			
			hst[it.first] = 1;
			q.push({it.first, it.second + val.second});
		}
	}
	
	return {node, max};
}
tiiv dfs(vector<pii> (&v)[50001], int begin)
{
	stack<pii> s;
	vector<int> path, ret;
	
	s.push({begin, 0});
	bool hst[50001]{};
	hst[begin] = 1;
	int max = 0, node = 0;
	
	while (!s.empty())
	{
		auto val = s.top();
		
		if (path.size() == 0 || path.back() != val.first)
		{
			path.push_back(val.first);
			tmp.push_back(val.second);
		}
		
		hst[val.first] = 1;
		
		if (max < val.second)
		{
			max = val.second;
			node = val.first;
			
			ret = path;
			subLen = tmp;
		}
		
		bool f = 0;
		for (auto &it : v[val.first])
		{
			if (hst[it.first]) continue;
			
			hst[it.first] = 1;
			s.push({it.first, it.second + val.second});
			f = 1;
			break;
		}
		
		if (f) continue;
		
		path.pop_back();
		tmp.pop_back();
		s.pop();
	}
	
	return {node, max, ret};
}
void findAns(vector<pii> (&v)[50001], bool h[], int dp[], int node)
{
	for (auto &it : v[node])
	{
		if (h[it.first]) continue;
		
		dp[it.first] = dp[node] + it.second;
		h[it.first] = 1;
		findAns(v, h, dp, it.first);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	
	vector<pii> v[50001];
	int from, to, len;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d %d", &from, &to, &len);
		
		v[from].push_back({to, len});
		v[to].push_back({from, len});
	}
	
	pii begin = bfs(v, 1);
	tiiv end = dfs(v, begin.first);
	
	int diameter = get<1>(end);
	int dp[50001];
	vector<int> path = get<2>(end);
	bool isInR[50001]{};
	for (auto &it : path) isInR[it] = 1;
	
	int left, right;
	for (int i = 0; i < path.size(); ++i)
	{
		left = subLen[i];
		right = diameter - subLen[i];
		
		dp[path[i]] = max(left, right);
		findAns(v, isInR, dp, path[i]);
	}
	
	//printf("%d -> %d, len: %d\n", begin.first, get<0>(end), get<1>(end));
	//for (auto &it : get<2>(end)) printf("%d ", it);
	
	//puts("");
	for (int i = 1; i <= n; ++i) printf("%d\n", dp[i]);
	
	return 0;
}