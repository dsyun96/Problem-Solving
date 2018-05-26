#include <cstdio>
#include <string>

using std::string;

void change(string a[], int idx, int dir, int f) //dir 1->cw, 0->ccw
{
	if (f !=  1 && idx > 0 && a[idx][6] != a[idx - 1][2]) change(a, idx - 1, dir ^ 1, -1);
	if (f != -1 && idx < 3 && a[idx][2] != a[idx + 1][6]) change(a, idx + 1, dir ^ 1,  1);

	if (dir) a[idx] = a[idx].back() + a[idx].substr(0, 7);
	else a[idx] = a[idx].substr(1, 7) + a[idx][0];
}
int main()
{
	char tmp[10];
	string dat[4];
	for (int i = 0; i < 4; ++i)
	{
		scanf(" %s", tmp);
		dat[i] = tmp;
	}

	int k, a, b;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d %d", &a, &b);
		change(dat, a - 1, b > 0, 0);
	}

	int ans = 0;
	for (int i = 0; i < 4; ++i)
		ans |= (dat[i][0] == '1') << i;

	printf("%d", ans);

	return 0;
}