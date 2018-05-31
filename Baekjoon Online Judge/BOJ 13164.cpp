#include <cstdio>
#include <algorithm>

using std::sort;

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);

	int prev, next, arr[300000];
	scanf("%d", &prev);
	for (int i = 0; i < n - 1; ++i)
	{
		scanf("%d", &next);
		arr[i] = next - prev;
		prev = next;
	}

	sort(arr, arr + n - 1);

	int sum = 0;
	for (int i = 0; i < n - k; ++i)
		sum += arr[i];

	printf("%d", sum);

	return 0;
}