#include <bits/stdc++.h>

using namespace std;

const int Maxn = 50;

int n, p;
string s[50];
long long apple, ans;

int main()
{
	cin >> n >> p;
	p >>= 1;
	for(int i = 1; i <= n; ++i)
		cin >> s[i];
	for(int i = n; i; --i)
	{
		if(s[i] == "half")
		{
			ans += apple*p;
			apple <<= 1;
		}
		else
		{
			apple += 1;
			ans += apple*p;
			apple <<= 1;
		}
	}
	cout << ans << endl;
	return 0;
}
