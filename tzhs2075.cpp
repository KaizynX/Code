#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxn = 22;

int tx[Maxn], ty[Maxn];
int x[4], y[4];
int maxx, maxy;

int main()
{
	for(int i = 0 ; i < 4; ++i)
	{
		scanf("%d%d", x+i, y+i);
		maxx = max(maxx, ++tx[x[i]]); 
		maxy = max(maxy, ++ty[y[i]]);
	}
	if(maxx == 4 || maxy == 4) puts("zhisi");
	else if(maxx == 3 || maxy == 3)
	{
		int maxn = 0, maxi = 0;
		for(int i = 1; i <= 19; ++i)
			if(maxx == 3 && maxn < ty[i]) { maxn = ty[i]; maxi = i; }
			else if(maxy == 3 && maxn < tx[i]) { maxn = ty[i]; maxi = i; }
		if(  (maxx == 3 && ty[maxi-1] && ty[maxi+1])
		  || (maxy == 3 && tx[maxi-1] && ty[maxi+1]) )
			puts("dingsi");
		else puts("qusi");
	}
	else
	{
		sort(x, x+4);
		sort(y, y+4);
		int kx = 1, ky = 1;
		for(int i = 1; i < 4; ++i)
		{
			if(x[i] != x[i-1]) kx++;
			if(y[i] != y[i-1]) ky++;
		}
		if(kx == ky) puts("fangsi");
		else puts("wansi");
	}
	return 0;
}
