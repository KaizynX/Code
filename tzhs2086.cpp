#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;
const int INF = 0x7fffffff;
const long long INFLL = 2e11;

int n, L;
int a[Maxn];
long long s[Maxn];

int main()
{
	int l = INF, r = 0;
	scanf("%d%d", &n, &L);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		a[i] *= 1000;
		l = min(l ,a[i]);
		r = max(r, a[i]);
	}
	while(l < r)
	{
		int mid = (l + r + 1) >> 1;
		for(int i = 1; i <= n; ++i)
			s[i] = s[i-1] + (a[i] - mid);
		long long res = -INFLL, mins = INFLL;
		for(int i = L; i <= n; ++i)
		{
			mins = min(mins, s[i-L]);
			res = max(res, s[i] - mins);
		}
		if(res >= 0) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}
