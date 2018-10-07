#include <bits/stdc++.h>

using namespace std;

long long k, L, s, w, p, ans;

inline long long qpow(long long a, long long x)
{
	long long res = 1;
	while(x)
	{
		if(x&1) res = res*a%p;
		x >>= 1;
		a = a*a%p;
	}
	return res;
}

int main()
{
	cin >> k >> L >> p >> s;
	long long k_1 = (k-1)%p, k_2 = (k-2)%p;
	k %= p;
	if(s)
	{
		cin >> w;
		if(L == 1) ans = 1;
		else if(s == 1 || s == L)
			ans = k_1*qpow(k_2, L-2)%p;
		else
		{
			ans = k_1*qpow(k_2, s-2)%p; // left
			ans = ans*qpow(k_2, L-s)%p; // right
		}
		cout << ans << endl;
	}
	else
	{
		if(L == 1) ans = k;
		else ans = k*k_1%p*qpow(k_2, L-2)%p;
		cout << ans << endl;
	}
	return 0;
}
