#include <cstdio>
#include <cstring>

int main()
{
	char crypto[105];
	scanf("%s", crypto);
	int clen = strlen(crypto);

	int n;
	scanf("%d", &n);

	char dat[25];
	while (n--)
	{
		scanf(" %s", dat);

		int k, dlen = strlen(dat);
		for (k = 0; k < 26; ++k)
		{
			for (int i = 0; i < clen; ++i)
				crypto[i] = (crypto[i] - 96) % 26 + 97;

			if (strstr(crypto, dat)) break;
		}

		if (k != 26) return puts(crypto) * 0;
	}

	return 0;
}