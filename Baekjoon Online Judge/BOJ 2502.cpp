#include <cstdio>
#include <algorithm>

using std::lower_bound;

int main()
{
	int arr[31] = { 1, 1, 2 };
	for (int i = 3; i < 31; ++i) arr[i] = arr[i - 1] + arr[i - 2];

	int d, k;
	scanf("%d %d", &d, &k);

	for (int a = 1; a < 100000; ++a)
		if ((k - arr[d - 3] * a) % arr[d - 2] == 0)
			return printf("%d\n%d", a, (k - arr[d - 3] * a) / arr[d - 2]) * 0;

	return 0;
}