#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 30;

int s, t, w, cnt;
char str[Maxn];
int num[Maxn], now[Maxn], vis[Maxn];

void dfs(int cur, int last)
{
	if(cnt > 5) return;
	if(cur == w)
	{
		++cnt;
		if(cnt == 1) return;
		for(int i = 0; i < w; ++i)
			putchar(now[i]+'a'-1);
		putchar('\n');
	}
	for(int i = last+1; i <= t; ++i)
	{
		if(!cnt) i = num[cur];
		if(vis[i]) continue;
		vis[i] = 1;
		now[cur] = i;
		dfs(cur+1, i);
		vis[i] = 0;
	}
}

int main()
{
	scanf("%d%d%d", &s, &t, &w);
	scanf("%s", str);
	for(int i = 0; i < w; ++i)
		num[i] = str[i]-'a'+1;
	dfs(0, s-1);
	return 0;
}
