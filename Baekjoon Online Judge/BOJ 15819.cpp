#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, i;
	cin >> n >> i;

	string dat[100];
	for (int i = 0; i < n; ++i)
		cin >> dat[i];
	
	nth_element(dat, dat + i - 1, dat + n);
	cout << dat[i - 1];

	return 0;
}