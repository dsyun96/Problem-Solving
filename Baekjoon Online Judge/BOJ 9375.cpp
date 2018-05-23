#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	int t;
	cin >> t;

	map<string, int> m;
	string name, kind;
	while (t--)
	{
		int n;
		cin >> n;

		while (n--)
		{
			cin >> name >> kind;
			++m[kind];
		}

		int ans = 1;
		for (auto &it : m) ans *= it.second + 1;

		cout << ans - 1 << '\n';
		m.clear();
	}

	return 0;
}