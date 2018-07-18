#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;
const int Mo = 99999997;

int n, ans;
int c[Maxn], tmp[Maxn];

struct Node
{
	int val, pos;
	bool operator < (const Node &b) const
	{
		return val < b.val;
	}
} a[Maxn], b[Maxn];

void merge_sort(int l, int r) // [l, r)
{
	if(r - l <= 1) return;

	int mid = (l + r) / 2;
	merge_sort(l, mid);        // [l, mid)
	merge_sort(mid, r);        // [mid, r)

	int i = l, j = mid, pos = l;
	while(pos < r)
	{
		if(i >= mid || j < r && c[j] < c[i])
		{
			ans = (ans + mid - i) % Mo;
			tmp[pos++] = c[j++];
		}
		else tmp[pos++] = c[i++];
	}
	for(int k = l; k < r; ++k)
		c[k] = tmp[k];
}

inline int getint()
{
	int res = 0;
	char c = getchar();
	while( c < '0' || c > '9' ) c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}

int main()
{
	n = getint();
	for(int i = 0; i < n; ++i)
	{
		a[i].val = getint();
		a[i].pos = i;
	}
	for(int i = 0; i < n; ++i)
	{
		b[i].val = getint();
		b[i].pos = i;
	}

	sort(a, a + n);
	sort(b, b + n);
	
	for(int i = 0; i < n; ++i)
	{
		c[ b[i].pos ] = a[i].pos;
	}

	merge_sort(0,n);

	cout << ans << endl;

	return 0;
}

