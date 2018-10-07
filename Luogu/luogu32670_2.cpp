#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e6;

int Q, l, r;
int s[Maxn+7];

inline void init()
{
	for(int i = 1, tmp, cur; i <= Maxn; ++i)
	{
		tmp = i;
		cur = 0;
		while(tmp)
		{
			cur += tmp%10;
			tmp /= 10;
		}
		s[i] = (s[i-1]+cur)%9;
	}
}

int main()
{
	init();
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d%d", &l, &r);
		printf("%d\n", (s[r]-s[l-1]+9)%9);
	}
	return 0;
}
