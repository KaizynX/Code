#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e6+7;

int n, s[Maxn];

int main()
{
	int l = Maxn, r = 0;
	scanf("%d", &n);
	for(int i = 0, a, b; i < n; ++i)
	{
		scanf("%d%d", &a, &b);
		s[l]++; s[r+1]--;
		l = min(l, a);
		r = max(r, b);
	}
	printf("%d ", l);
	int cur = 0, flag = true;
	for(int i = l; i <= r; ++i)
	{
		cur += s[i];
		if(!cur && flag)
		{
			printf("%d\n", i-1);
			flag = false;
		}
		if(cur && !flag)
		{
			printf("%d ", i);
			flag = true;
		}
	}
	printf("%d\n", r);
	return 0;
}
