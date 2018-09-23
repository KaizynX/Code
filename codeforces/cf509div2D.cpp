#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e5+7;

int n, H, ans;
int a[Maxn<<1];

int main()
{
	scanf("%d%d", &n, &H);
	for(int i = 1; i <= n*2; ++i)
		scanf("%d", a+i);
	int head = 1, tail = 1, curx = 0, curh = H, tmp;
	ans = H+a[2]-a[1];
	while(tail <= n*2)
	{
		while(tail <= n*2)
		{
			if(tail&1)
			{
				if(curh <= 0) break;
				curx += a[tail+1]-a[tail];
				tail++;
			}
			else
			{
				tmp = a[tail+1]-a[tail];
				if(curh-tmp >= 0)
				{
					curx += tmp;
					curh -= tmp;
					tail++;
				}
				else break;
			}
			ans = max(ans, curx+curh);
		}
		// can't move now
		// head is odd
		if(head >= tail) break;
		curx -= a[head+1]-a[head];
		head++;
		// head is even
		if(head >= tail) break;
		curx -= a[head+1]-a[head];
		curh += a[head+1]-a[head];
		head++;
	}
	printf("%d\n", ans);
	return 0;
}
