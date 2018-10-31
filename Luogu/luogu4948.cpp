// Brute_Force 40
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

long long n, ans;
int a, k;

void exgcd(int a, int b, int &x, int &y)
{
	if(!b) { x = 1; y = 0; return; }
	exgcd(b, a%b, y, x);
	y -= a/b*x;
}

inline int mul_inverse(int a, int mo)
{
	int x, y;
	exgcd(a, mo, x, y);
	return (x%mo+mo)%mo;
}

inline long long qpow(long long a, long long p, int mo)
{
	long long res = 1;
	while(p)
	{
		if(p&1) res = res*a%mo;
		a = a*a%mo;
		p >>= 1;
	}
	return res;
}

int main()
{
	cin >> n >> a >> k;
	if(k == 0)
		ans = (qpow(a, n, MOD)-1)*a%MOD*mul_inverse(a-1, MOD)%MOD;
	else if(k == 1)
	{
		ans = (qpow(a, n, MOD)-1)*a%MOD*mul_inverse(a-1, MOD)%MOD;
		ans = mul_inverse(a-1, MOD)*(n%MOD*qpow(a, n+1, MOD)%MOD-ans+MOD)%MOD;
	}
	else
	{
		long long cur = 1; // cur = a^i
		for(int i = 1; i <= n; ++i)
		{
			cur = cur*a%MOD;
			ans = (ans+qpow(i, k, MOD)*cur%MOD)%MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
