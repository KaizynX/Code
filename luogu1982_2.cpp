#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e6+7;

int n, p, a, flag;
long long b[Maxn], m, cur, maxsum, maxsumb;

int main()
{
	scanf("%d%d%d", &n, &p, &a);
	maxsum = b[1] = cur = a;
	if(a > 0) flag = 1;
	if(cur < 0) cur = 0;
	for(int i = 2; i <= n; ++i)
	{
		scanf("%d", &a);
		cur += a;
		b[i] = maxsum = max(maxsum, cur);
		if(cur < 0) cur = 0;
		if(i == 2) m = 2*b[1];
		else if(b[i-1] > 0)
		{
			m = (m+b[i-1])%p;
			if(!flag && (maxsumb += b[i-1]) >= -b[1]) flag = 1;
		}
	}
	if(flag) printf("%lld\n", m);
	else printf("%lld\n", b[1]%p);
	return 0;
}
