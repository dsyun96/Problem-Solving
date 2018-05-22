#include <cstdio>
#include <cstring>

int main()
{
	char input[40], dat[10];

	scanf("%s", input);
	if (strchr(input, 'x'))
	{
		if (sscanf(input, "%[^x]", dat)) printf(strcmp(dat, "-") ? "%s" : "-1", dat);
		else printf("1");
	}
	else printf("0");

	return 0;
}