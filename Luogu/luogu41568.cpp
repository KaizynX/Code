#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int n;

inline long long quickm(long long a, int p)
{
	long long res = 1;
	while(p)
	{
		if(p&1) res = res*a%MOD;
		p >>= 1;
		a = a*a%MOD;
	}
	return res;
}

int main()
{
	cin >> n;
	cout << (quickm(2, n-1)*(n-2)+1)%MOD << endl;
	return 0;
}
