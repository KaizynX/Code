#include <cstdio>
#include <iostream>

using namespace std;

int Q, l, r;
int ten[10];

inline int cont(int x)
{
	int l = 0, r = 9, mid;
	while(l < r)
	{
		mid = (l+r)>>1;
		if(x < ten[mid]) r = mid;
		else l = mid+1;
	}
	return ten[l];
}

inline void init()
{
	ten[0] = 1;
	for(int i = 1; i <= 9; ++i)
		ten[i] = ten[i-1]*10;
}

int main()
{
	init();
	int cur;
	scanf("%d", &Q);
	while(Q--)
	{
		cur = 0;
		scanf("%d%d", &l, &r);
		for(int i = l; i <= r; ++i)
		{
			if(!cur) cur = i%9;
			else cur = (cur*cont(i)+i)%9;
		}
		printf("%d\n", cur);
	}
	return 0;
}
