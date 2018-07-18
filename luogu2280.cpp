#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int Maxn = 5000 + 7;

int n, r, ans, minx, maxx, miny, maxy;
map <pair<int,int>,int> m;
int s[Maxn][Maxn];

inline int getint();

int main()
{
	n = getint(); r = getint();
	minx = Maxn; miny = Maxn; // maxx = 0; maxy = 0;
	for(int i = 0,x,y,v; i < n; ++i)
	{
		x = getint(); y = getint(); v = getint();
		// x,y may == 0;
		++x; ++y;
		if(x < minx) minx = x; 
		if(x > maxx) maxx = x;
		if(y < miny) miny = y; 
		if(y > miny) maxy = y;
		m.insert( make_pair( make_pair(x, y), v) );
	}
	for(int i = minx; i <= maxx; ++i)
		for(int j = minx; j <= maxy; ++j)
		{
			s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1];
			if(m.count(make_pair(i,j))) s[i][j] += m[make_pair(i,j)];
		}

	for(int i = minx+r-1; i <= maxx; ++i)
		for(int j = miny+r-1; j <= maxy; ++j)
		{
			ans = max(ans,s[i][j] - s[i-r][j] - s[i][j-r] + s[i-r][j-r]);
		}

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
