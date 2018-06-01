#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 2e4 + 7;
const int Maxm = 1e5 + 7;

int n, m;
int par[Maxn], enm[Maxn]; // partner & enemy
struct Node
{
	int x, y, v;
	bool operator < (const Node &b) const { return v < b.v;}
} a[Maxm];

int getp(int s) { return par[s] == s ? par[s] : par[s] = getp(par[s]); }

int main()
{
	freopen("love.in","r",stdin);
	freopen("love.out","w",stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) par[i] = i;
	for(int i = 0; i < m; ++i) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].v);
	sort(a, a+m); reverse(a, a+m);
	for(int i = 0, x, y, ex, ey; i < m; ++i)
	{
		x = a[i].x; y = a[i].y;
		ex = enm[x]; ey = enm[y];
		// if a point hadn't been visited, its enm is 0
		if(!ex && !ey) // set this two to oppsite
		{
			enm[x] = y;
			enm[y] = x;
		}
		else if(!ex && ey) // set x to y's enemy
		{
			par[x] = getp(ey);
			enm[x] = getp(y);
		}
		else if(ex && !ey)
		{
			par[y] = getp(ex);
			enm[y] = getp(x);
		}
		// ex !=0 && ey !=0
		else if(getp(ex) != getp(ey)) // connect(ex,py) (ey,px)
		{
			par[getp(y)] = getp(ex);
			par[getp(x)] = getp(ey);
		}
		else
		{
			printf("%d\n",a[i].v);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
