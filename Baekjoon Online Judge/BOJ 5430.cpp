#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);

	char p[100001];
	while (T--)
	{
		int n, arr[100000];
		scanf(" %s %d", p, &n);

		while (getchar() != '[');
		if (n == 0) getchar();

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", arr + i);
			getchar();
		}

		int begin = 0, end = n - 1, state = 0; //0 origin, 1 reverse
		for (int i = 0; p[i]; ++i)
		{
			if (p[i] == 'R') state ^= 1;
			else
			{
				if (state) --end;
				else ++begin;
			}
		}

		if (begin - 1 > end) puts("error");
		else
		{
			if (begin - 1 == end) puts("[]");
			else if (begin == end) printf("[%d]\n", arr[begin]);
			else
			{
				if (state == 0)
				{
					printf("[%d", arr[begin++]);
					for (int i = begin; i <= end; ++i) printf(",%d", arr[i]);
					puts("]");
				}
				else
				{
					printf("[%d", arr[end--]);
					for (int i = end; i >= begin; --i) printf(",%d", arr[i]);
					puts("]");
				}
			}
		}
	}

	return 0;
}