#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 60;
const int Maxk = 5;
const int INF = 0x3f3f3f3f;

int n, k, ans = INF;

struct Point
{
	int x, y;
} a[Maxn];

struct Square
{
	int lx, rx, ly, ry;
	Square(){ lx = rx = ly = ry = -1; }
	inline void addjust(Point &p)
	{
		if(lx == -1) // all is -1
		{
			lx = rx = p.x;
			ly = ry = p.y;
		}
		else
		{
			lx = min(lx, p.x);
			rx = max(rx, p.x);
			ly = min(ly, p.y);
			ry = max(ry, p.y);
		}
	}
	inline int calc()
	{
		return (rx-lx)*(ry-ly);
	}
} s[Maxk];

inline bool judge(int i)
{
	for(int j = 1; j <= k; ++j)
	{
		if(i == j) continue;
		if(( (s[i].lx >= s[j].lx && s[i].lx <= s[j].rx)
		   ||(s[j].lx >= s[i].lx && s[j].lx <= s[i].rx))
		&& ( (s[i].ly >= s[j].ly && s[i].ly <= s[j].ry)
		   ||(s[j].ly >= s[i].ly && s[j].ly <= s[i].ry)))
			return false;
	}
	return true;
}

inline void update()
{
	int tmp = 0;
	for(int i = 1; i <= k; ++i)
		tmp += s[i].calc();
#ifdef DEBUG
	if(tmp < ans)
	{
		for(int i = 1; i <= k; ++i)
			printf("%d %d %d %d %d\n", s[i].lx, s[i].rx, s[i].ly, s[i].ry, s[i].calc());
		putchar('\n');
	}
#endif
	ans = min(ans, tmp);
}

void search(int cur)
{
	if(cur == n)
	{
		update();
		return;
	}
	for(int i = 1; i <= k; ++i)
	{
		Square tmp = s[i];
		s[i].addjust(a[cur]);
		if(judge(i) && s[i].calc() < ans)
			search(cur+1);
		s[i] = tmp;
	}
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	search(0);
	printf("%d\n", ans);
	return 0;
}
