#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 30;

int n, r, a[Maxn], v[Maxn];

void solve(int cur, int last)
{
	if(cur > r)
	{
		for(int i = 1; i <= r; ++i)
			printf("%3d", a[i]);
		putchar('\n');
		return;
	}
	for(int i = last+1; i <= n; ++i)
	{
		if(v[i]) continue;
		a[cur] = i;
		v[i] = 1;
		solve(cur+1, i);
		v[i] = 0;
	}
}

int main()
{
	scanf("%d%d", &n, &r);
	solve(1, 0);
	return 0;
}
