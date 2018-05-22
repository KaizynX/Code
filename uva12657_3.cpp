#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;

int n, m , kase;
int Left[Maxn], Right[Maxn];

inline void link(int L, int R)
{
	Right[L] = R; Left[R] = L;
}

int main()
{
	while(scanf("%d%d",&n,&m) == 2)
	{
		for(int i = 1; i <= n; ++i)
		{
			Left[i] = i-1;
			Right[i] = (i+1) % (n+1);
		}
		Right[0] = 1; Left[0] = n;
		int op, X, Y, inv = 0;

		while(m--)
		{
			scanf("%d",&op);
			if(op == 4) inv = !inv;
			else
			{
				scanf("%d%d",&X,&Y);
				if(op == 3 && Right[Y] == X) swap(X,Y);
				if(op != 3 && inv) op = 3 - op;
				if(op == 1 && X == Left[Y]) continue;
				if(op == 2 && X == Right[Y]) continue;

				int LX = Left[X], RX = Right[X], LY = Left[Y], RY = Right[Y];
				if(op == 1)
				{
					link(LX,RX); link(LY,X); link(X,Y);
				}
				else if(op == 2)
				{
					link(LX,RX); link(Y,X); link(X,RY);
				}
				else if(op == 3)
				{
					if(Right[X] == Y)
					{
						link(LX,Y); link(Y,X); link(X,RY);
					}
					else 
					{
						link(LX,Y); link(Y,RX); link(LY,X); link(X,RY);
					}
				}
			}
		}

		int b = 0;
		long long ans = 0;
		for(int i = 1; i <= n; ++i)
		{
			b = Right[b];
			if(i % 2 == 1) ans += b;
		}
		if(inv && n % 2 == 0) ans = (long long)n*(n+1)/2 - ans;
		printf("Case %d: %lld\n",++kase,ans);
	}
	return 0;
}
