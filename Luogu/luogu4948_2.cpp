#include <bits/stdc++.h>

using namespace std;

const int Maxk = 2e3+7;
const int MOD = 1e9+7;

long long n;
int a, k, inv;
int C[Maxk][Maxk];
long long T[Maxk];

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
	a %= mo;
	while(p)
	{
		if(p&1) res = res*a%mo;
		a = a*a%mo;
		p >>= 1;
	}
	return res;
}

inline void init()
{
	for(int i = 1; i <= k; ++i)
	{
		C[i][0] = C[i][i] = 1;
		for(int j = 1; j <= i/2; ++j)
			C[i][j] = C[i][i-j] = (C[i-1][j-1]+C[i-1][j])%MOD;
	}

	inv = mul_inverse(a-1, MOD);
	T[0] = (qpow(a, n, MOD)-1+MOD)%MOD*a%MOD*inv%MOD;
}

int main()
{
	cin >> n >> a >> k;
	init();
	long long tmpn = n%MOD, // tmpn = n^i
			  tmpa = qpow(a, n+1, MOD);

	for(int i = 1; i <= k; ++i)
	{
		T[i] = (tmpn*tmpa%MOD-a+MOD)%MOD;
		tmpn = tmpn*(n%MOD)%MOD;
		for(int j = 0, flag; j < i; ++j)
		{
			flag = (i-j)&1 ? -1 : 1;
			T[i] = (T[i]+((T[j]-a+MOD)%MOD*C[i][j]%MOD*flag+MOD)%MOD)%MOD;
		}
		T[i] = T[i]*inv%MOD;
	}

	cout << T[k] << endl;
	return 0;
}
