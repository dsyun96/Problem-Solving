#include <cstdio>
#include <utility>
#include <cstdint>
#include <algorithm>

using std::pair;
using std::sort;

int main()
{
	int n, x, y;
	scanf("%d", &n);

	pair<int, int> p[1000000];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &x, &y);
		p[i].first = x >> 1;
		p[i].second = y >> 1;
	}

	sort(p, p + n);

	int max = 0;
	int64_t ans = 0;
	for (int i = n - 1; ~i; --i)
	{
		const auto &r = p[i];

		if (r.second > max)
		{
			ans += int64_t(r.second - max) * r.first;
			max = r.second;
		}
	}

	printf("%lld", ans * 4);

	return 0;
}