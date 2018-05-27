#include <cstdio>

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	int arr[1000][1000];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", arr[i] + j);

	int max = 0;
	for (int i = 0; i < n; ++i)
		if (arr[i][b - 1] > max) max = arr[i][b - 1];

	for (int i = 0; i < n; ++i)
		if (arr[a - 1][i] > max) max = arr[a - 1][i];

	puts(max == arr[a - 1][b - 1] ? "HAPPY" : "ANGRY");

	return 0;
}