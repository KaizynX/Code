#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n, k;
int a[Maxn];
long long sum;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		sum += a[i];
	}
	for(int i = 1; i <= k; ++i)
	{
		int cnt = 1, minv = a[i], cur = i;
		while( (cur+=k) <= n)
		{
			cnt++;
			// we can only take the odd one
			// if we take the even one, the num before it become odd
			if(a[cur] < minv && cnt & 1) minv = a[cur];
		}
		if(cnt & 1) sum -= minv;
	}
	printf("%lld\n", sum);
	return 0;
}
