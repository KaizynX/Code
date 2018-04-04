#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int Maxn = 2500 + 7;
const int Maxm = 6200 + 7;
const int INF = 0x3f3f3f3f;

int T, C, Ts, Te;
int a[Maxn][Maxn];
int dis[Maxn];
bool vis[Maxn];

void f()
{
	int minv,mini;
	memset(vis,0,sizeof vis);
	memset(dis,0x3f,sizeof dis);
	dis[Ts] = 0;

	for(int k = 1; k < T; ++k)
	{
		minv = INF;
		for(int i = 1; i <= T; ++i)
		{
			if(!vis[i] && dis[i] < minv)
			{
				minv = dis[i];
				mini = i;
			}
		}

		if(mini == Te) return;
		vis[mini] = true;

		for(int i = 1; i <= T; ++i)
		{
			if(a[mini][i])
			{
				if(dis[i] > dis[mini] + a[mini][i])
					dis[i] = dis[mini] + a[mini][i];
			}
		}
	}
}

int main()
{
	int Rs, Re, Ci;
	scanf("%d%d%d%d",&T,&C,&Ts,&Te);
	for(int i = 0; i < C; ++i)
	{
		scanf("%d%d%d",&Rs,&Re,&Ci);
		a[Rs][Re] = a[Re][Rs] = Ci;
	}
	// Dijistra
	f();
	printf("%d\n",dis[Te]);
	return 0;
}
