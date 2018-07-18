#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 1<<21;

int l, d, n, cur;
bool vis[Maxn];

int main()
{
	scanf("%d",&l);
	while(l--)
	{
		memset(vis,0,sizeof vis);
		scanf("%d%d",&d,&n);

		for(int i = 0; i < n; ++i)
		{
			cur = 1;
			for(int j = 1; j < d; ++j)
			{
				vis[cur] = !vis[cur];
				if(vis[cur]) cur = cur * 2;
				else cur = cur * 2 + 1;
			}
		}
		printf("%d\n",cur);
	}
	scanf("%d",&n); // -1
	return 0;
}
