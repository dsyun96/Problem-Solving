#include <cstdio>

int main()
{
	int c;
	scanf("%d", &c);

	int arr[101] = { 0, 1, 2 };
	for (int i = 3; i < 101; ++i)
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000007;
	
	while (c--)
	{
		int n;
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}

	return 0;
}