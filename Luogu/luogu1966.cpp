#include <cstdio>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

const int Maxn = 1e5 + 7;
const int Mo = 99999997;

int n, ans;
int tmp[Maxn];

struct Node
{
	int x, y;
	bool operator < (const Node &nex) const
	{
		return x < nex.x;
	}
} a[Maxn];

void merge_sort(int l, int r) // [l, r)
{
	if(r - l <= 1) return;    // [l, l+1)
	int mid = (l + r) / 2;
	merge_sort(l, mid);       // [l, mid)
	merge_sort(mid, r);       // [mid, r)

	int i = l, j = mid, pos = l;
	while(pos < r)
	{
		// if (i >= mid) j must < r; cause pos < r
		if(i >= mid || j < r && a[i].y > a[j].y)
		{
			ans = (ans + mid - i) % Mo;
			tmp[pos++] = a[j++].y;
		}
		else
			tmp[pos++] = a[i++].y;
	}
	for(int k = l; k < r;++k)
		a[k].y = tmp[k];
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
		scanf("%d",&a[i].x);
	for(int i = 0; i < n; ++i)
		scanf("%d",&a[i].y);
	
	sort(a, a + n);
	merge_sort(0, n);
#ifdef DEBUG
	for(int i = 0; i < n; ++i)
		printf("%d %d\n",a[i].x,a[i].y);
#endif
	printf("%d\n",ans);
	return 0;
}
