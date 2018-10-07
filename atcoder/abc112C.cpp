#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int n;

struct Node
{
	int x, y, h;
	bool operator < (const Node &b) const
	{
		return h > b.h;
	}
} a[Maxn];

inline int calc(int x, int y, Node b)
{
	return b.h+abs(x-b.x)+abs(y-b.y);
}

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].x >> a[i].y >> a[i].h;
	sort(a+1, a+n+1);
	for(int i = 0; i <= 100; ++i)
	{
		for(int j = 0; j <= 100; ++j)
		{
			int H = calc(i, j, a[1]), flag = 1;
			for(int k = 2; k <= n; ++k)
			{
				if(a[k].h == 0 && H-abs(i-a[k].x)-abs(j-a[k].y) > 0)
				{
					flag = 0;
					break;
				}
				else if(a[k].h > 0 && calc(i, j, a[k]) != H)
				{
					flag = 0;
					break;
				}
			}
			if(flag)
			{
				cout << i << " " << j << " " << H << endl;
				return 0;
			}
		}
	}
	return 0;
}
