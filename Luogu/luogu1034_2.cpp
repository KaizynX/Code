#include <cstdio>
#include <iostream>
#include <algorithm>
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
		pair<int, int> tmpx[4], tmpy[4];
		tmpx[0] = make_pair(s[i].lx, i);
		tmpx[1] = make_pair(s[i].rx, i);
		tmpx[2] = make_pair(s[j].lx, j);
		tmpx[3] = make_pair(s[j].rx, j);
		tmpy[0] = make_pair(s[i].ly, i);
		tmpy[1] = make_pair(s[i].ry, i);
		tmpy[2] = make_pair(s[j].ly, j);
		tmpy[3] = make_pair(s[j].ry, j);
		sort(tmpx, tmpx+4); sort(tmpy, tmpy+4);
		if((tmpx[0].second != tmpx[1].second || tmpx[2].first == tmpx[3].first)
		&& (tmpy[0].second != tmpy[1].second || tmpy[2].first == tmpy[3].first))
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
