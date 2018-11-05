#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);

	int arr[10000];
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);

	sort(arr, arr + n);

	int ans = 0;
	for (int i = 0; i < n; ++i) if (i == 0 || arr[i] != arr[i - 1]) {
		int j = i + 1, k = n - 1, prv = arr[j] - 1;
		while (j < k) {
			int tmp = arr[i] + arr[j] + arr[k];

			if (tmp > 0) --k;
			else if (tmp < 0) ++j;
			else {
				if (prv != arr[j]) {
					++ans;
					prv = arr[j];
				}
				--k;
				++j;
			}
		}
	}

	printf("%d", ans);

	return 0;
}
