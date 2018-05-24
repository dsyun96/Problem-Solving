#include <cstdio>
#include <algorithm>

using std::lower_bound;

int main()
{
	int org[100000], lis[100000];
	for (int n; ~scanf("%d", &n); )
	{
		for (int i = 0; i < n; ++i) scanf("%d", org + i);

		int size = 0;
		for (int i = 0; i < n; ++i)
		{
			int *p = lower_bound(lis, lis + size, org[i]);

			lis[p - lis] = org[i];
			size += p == lis + size;
		}

		printf("%d\n", size);
	}

	return 0;
}