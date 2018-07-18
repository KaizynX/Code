#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n, k;

int main()
{
	cin >> n >> k;
	if(n < k || (k <= 1 && n > 1))
	{
		cout << "-1";
		return 0;
	}
	if(n == 1 && k == 1)
	{
		cout << 'a';
		return 0;
	}
	for(int i = 1; i <= n - k + 2; ++i)
		cout << (i % 2 == 0 ? 'b' : 'a');
	for(int i = 3; i <= k; ++i)
		cout << char('a' + i - 1);
	return 0;
}
