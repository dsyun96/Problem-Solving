#include <cstdio>
#include <stack>
#include <utility>

using std::stack;
using std::pair;
typedef pair<int, int> pii;

int main()
{
	int n, v;
	scanf("%d", &n);

	stack<pii> s;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);

		if (s.empty()) printf("%d", 0);
		else if (s.top().first >= v) printf(" %d", s.top().second);
		else
		{
			while (!s.empty() && s.top().first < v) s.pop();
			if (s.empty()) printf(" %d", 0);
			else printf(" %d", s.top().second);
		}

		s.push({ v, i + 1 });
	}

	return 0;
}