#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e6+7;

int n, k, a[Maxn];
int ql[Maxn], qg[Maxn], sl, tl, sg, tg;
int rg[Maxn], cnt;

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	sl = sg = 1;
	tl = tg = 0;
	for(int i = 1; i <= k; ++i)
	{
		while(sl <= tl && a[ql[tl]] >= a[i]) tl--;
		while(sg <= tg && a[qg[tg]] <= a[i]) tg--;
		ql[++tl] = i;
		qg[++tg] = i;
	}
	for(int i = k; i <= n; ++i)
	{
		while(sl <= tl && ql[sl] <= i-k) sl++;
		while(sg <= tg && qg[sg] <= i-k) sg++;
		printf("%d ", a[ql[sl]]);
		rg[++cnt] = a[qg[sg]];
		if(i+1 > n) continue;
		while(sl <= tl && a[ql[tl]] >= a[i+1]) tl--;
		while(sg <= tg && a[qg[tg]] <= a[i+1]) tg--;
		ql[++tl] = i+1;
		qg[++tg] = i+1;
	}
	putchar('\n');
	for(int i = 1; i <= cnt; ++i)
		printf("%d ", rg[i]);
	putchar('\n');
	return 0;
}
