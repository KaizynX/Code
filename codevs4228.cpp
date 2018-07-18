#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int Maxn = 20;

int n, w, ans;
int cab[Maxn], a[Maxn];

inline int getint();

void dfs(int cur,int cnt)
{
	if(cur >= n)
	{
		if(cnt < ans) ans = cnt;
		return;
	}
	if(cnt >= ans) return;

	for(int i = 1; i <= cnt; ++i)
	{
		if(w - cab[i] >= a[cur])
		{
			cab[i] += a[cur];
			dfs(cur+1,cnt);
			cab[i] -= a[cur];
		}
	}

	cab[cnt+1] = a[cur];
	dfs(cur+1, cnt+1);
	cab[cnt+1] = 0;
}

int main()
{
	n = getint(); w = getint();
	for(int i = 0; i < n; ++i) a[i] = getint();
	sort(a,a+n); reverse(a,a+n);
	ans = n;

	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res;
}
