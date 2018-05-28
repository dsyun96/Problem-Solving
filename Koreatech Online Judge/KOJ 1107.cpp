#include <cstdio>
#include <cstring>

int main()
{
	int n;
	scanf("%d%*c", &n);

	char tmp[1001];
	while (n--)
	{
		if (!scanf("%[^\n]", tmp)) tmp[0] = 0;

		int cnt = 0;
		for (int i = 0; tmp[i]; ++i)
			if (strchr("aeiou", tmp[i])) ++cnt;

		printf("%d\n", cnt);
		getchar();
	}

	return 0;
}