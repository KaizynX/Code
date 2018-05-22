#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int INF = 0x7fffffff;
const int Maxn = 2e5;

int n, l, r, T;
int ans[2*Maxn];

void read_tree(int d)
{
	int v;
	scanf("%d",&v);
	if(v == -1) return;
	++n;
	l = min(l,d);
	r = max(r,d);
	ans[d] += v;
	read_tree(d-1);
	read_tree(d+1);
}

int main()
{
	l = INF; r = -INF;
	while(1)
	{
		read_tree(Maxn);
		if(!n) break; // read only -1
		printf("Case %d:\n%d",++T,ans[l]);
		for(int i = l+1; i <= r; ++i)
			printf(" %d",ans[i]);
		printf("\n\n");
		memset(ans,0,sizeof ans);
		n = 0; l = INF; r = -INF;
	}
	return 0;
}
