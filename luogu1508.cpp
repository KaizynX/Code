#include <iostream>

using namespace std;

const int Maxn = 200 + 7;
const int INF = 0x3f3f3f3f;

/*   n n n 
 * m
 * m
 */

int n, m;
int a[Maxn][Maxn];
int f[Maxn][Maxn];

inline int max(int &a, int &b) { return a < b ? b : a; }
inline int max3(int &a, int &b, int &c) { return max(max(a,b),c); }

int main()
{
	cin >> m >> n;
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			cin >> a[i][j];
	/*
	int mid = n/2+1;
	for(int i = m; i >= 1; --i)
		for(int j = max(1, mid-m+i-1); j <= min(n, mid-m+i-1); ++j)
	*/
	for(int i = 1; i <= n; ++i) f[1][i] = a[1][i];
	for(int i = 2; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
			f[i][j] = max3(f[i-1][j-1],f[i-1][j],f[i-1][j+1]) + a[i][j];
	int mid = n/2+1;
	cout << max3(f[m][mid-1],f[m][mid],f[m][mid+1]) << endl;
	return 0;
}
