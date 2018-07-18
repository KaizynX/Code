#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Maxm = 5000 + 7;

int n, r, ans;
int a[Maxm][Maxm];

inline int getint();

int main()
{
	n = getint(); r = getint();
	for(int i = 0,x,y,v; i < n; ++i)
	{
		x = getint(); y = getint(); v = getint();
		a[x+1][y+1] = v; // x,y may == 0
	}
	// brute
	for(int i = 1; i <= 5001; ++i)
		for(int j = 1; j <= 5001; ++j)
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + a[i][j];
	for(int i = r; i <= 5001; ++i)
		for(int j = r; j <= 5001; ++j)
			ans = max(ans,a[i][j] - a[i-r][j] - a[i][j-r] + a[i-r][j-r]);

	printf("%d\n",ans);
	return 0;
}

inline int getint()
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	int res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	return res;
}
