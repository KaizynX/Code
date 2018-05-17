#include <cstdio>
#include <iostream>

using namespace std;

int l, d, n, cur;

int main()
{
	scanf("%d",&l);
	while(l--)
	{
		scanf("%d%d",&d,&n);

		cur = 1;
		for(int i = 1; i < d; ++i)
		{
			if(n & 1) { cur <<= 1; n = (n+1) >> 1; }
			else { cur = (cur<<1)+1; n >>= 1; }
		}
		printf("%d\n",cur);
	}
	scanf("%d",&n); // -1
	return 0;
}

