#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define BigInteger long long

using namespace std;

const int Maxn = 80 + 7;

/*
struct BigInteger
{
	BigInteger(){}
};
*/

int n, m;
int a[Maxn];
BigInteger ans, maxf, f[Maxn][Maxn];
// f[l][r] ==> the max value of taking l left num and r right num

int main()
{
	scanf("%d%d", &n, &m);
	while(n--)
	{
		for(int i = 1; i <= m; ++i) scanf("%d", a+i);
		memset(f, 0, sizeof f);
		for(int k = 1; k <= m; ++k) // take k number
		{
			for(int l = 0, r; l <= k; ++l)
			{
				r = k - l;
				if(l - 1 >= 0) f[l][r] = max(f[l][r], f[l-1][r]*2+a[l]);
				if(r - 1 >= 0) f[l][r] = max(f[l][r], f[l][r-1]*2+a[m-r+1]);
			}
		}
		maxf = 0;
		for(int l = 0; l <= m; ++l) maxf = max(maxf, f[l][m-l]);
		ans += maxf * 2;
	}
	cout << ans << endl;
	return 0;
}
