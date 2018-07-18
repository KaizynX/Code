#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 1e5 + 7;

int n, cnt;
int a[Maxn];
bool vis[Maxn];

int main()
{
	int tmp,mid;
	while(scanf("%d",&tmp) && tmp)
	{
		a[n=cnt=mid=1] = tmp;
		memset(vis,0,sizeof vis);
		while(scanf("%d",&tmp))
		{
			if(!tmp) break;
			if(tmp == -1)
			{
				printf("%d\n",a[mid]);
				// then delete a[mid]
				vis[mid] = true;
				if(--cnt & 1) while(vis[++mid]);
				else while(vis[--mid]);
				// if(!mid) mid = 1; // cnt ==1
			}
			else
			{
				a[++n] = tmp;
				++cnt;
				if(cnt & 1) while(vis[++mid]);
			}
		}
		putchar('\n');
	}
	return 0;
}
