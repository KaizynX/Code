#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 107;
const int INF = 2e5;

int n, k, f[Maxn][Maxn], ans = INF;
// f[i][j] choose i book and the last one is j
struct Book
{
	int l, d;
	bool operator < (const Book &b) const
	{
		return l < b.l;
	}
} a[Maxn];

int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].l >> a[i].d;
	sort(a+1, a+n+1);
	for(int i = 2; i <= n-k; ++i)
		for(int j = i; j <= n; ++j)
		{
			f[i][j] = INF;
			for(int m = i-1; m < j; ++m)
				f[i][j] = min(f[i][j], f[i-1][m] + abs(a[j].d - a[m].d));
			if(i == n-k) ans = min(ans, f[i][j]);
		}
	cout << ans << endl;
	return 0;
}
