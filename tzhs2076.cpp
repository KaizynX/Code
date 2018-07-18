#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define DEBUG

using namespace std;

int n, ans;
int f1 = 1, f2 = 33;

int main()
{
	scanf("%d", &n);
	while(n--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int dis1 = abs(x - f1), dis2 = abs(x - f2), dis = abs(x- y);
#ifdef DEBUG
		printf("%d %d %d ", dis1, dis2, dis);
#endif
		if(dis1 < dis2)
		{
			ans += dis1 + dis;
			f1 = y;
		}
		else if(dis1 > dis2)
		{
			ans += dis2 + dis;
			f2 = y;
		}
		else
		{
			int *f= &f1;
			if(f1 != f2)
			{
				if(x < y) f = (f1 < f2 ? &f1 : &f2);
				else f = (f1 > f2 ? &f1 : &f2);
			}
#ifdef DEBUG
			printf(" %d %d %d ", f1, f2, *f);
#endif
			ans += dis1 + dis;
			*f = y;
		}
#ifdef DEBUG
		printf("%d\n", ans);
#endif
	}
	printf("%d\n", ans);
	return 0;
}
