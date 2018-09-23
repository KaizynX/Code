#include <cstdio>
#include <iostream>

using namespace std;

int Q, l, r;

inline int calc(int x)
{
	tmp = i;
	cur = 0;
	while(tmp)
	{
		cur += tmp%10;
		tmp /= 10;
	}
	return cur%9;
}

int main()
{
	scanf("%d", &Q);
	while(Q--)
	{
		scanf("%d%d", &l, &r);
	}
	return 0;
}
