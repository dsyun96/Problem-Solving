#include <cstdio>
#include <string>
#include <map>
#include <set>

using std::map;
using std::set;
using std::string;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	map<string, int> d;
	set<string> ans;
	char tmp[25];
	for (int i = 0; i < n; ++i)
	{
		scanf(" %s", tmp);
		++d[tmp];
	}

	for (int i = 0; i < m; ++i)
	{
		scanf(" %s", tmp);
		if (d[tmp]) ans.insert(tmp);
	}

	printf("%d\n", ans.size());
	for (auto &it : ans) puts(it.c_str());

	return 0;
}