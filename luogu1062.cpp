#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1007;
const int Maxk = 15;

int k, n;
long long ans;

int main()
{
	scanf("%d%d", &k, &n);
	for(long long tmp = 1; n; n >>= 1)
	{
		if(n&1) ans += tmp;
		tmp *= k;
	}
	printf("%lld\n", ans);
	return 0;
}
