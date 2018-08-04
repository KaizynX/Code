#include <iostream>

using namespace std;

const int Maxn = 20;

int n, m, a[Maxn][Maxn], f[Maxn][Maxn], p[Maxn][Maxn], num[Maxn];
// f[i][j] give j mashine to 1~i company

int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			cin >> a[i][j];
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0, tmp; k <= j; ++k)
			{
				// f[i][j] = max(f[i][j], f[i-1][k] + a[i][j-k]);
				tmp = f[i-1][k] + a[i][j-k];
				if(f[i][j] < tmp)
				{
					f[i][j] = tmp;
					p[i][j] = k;
				}
			}
	cout << f[n][m] << endl;
	for(int i = n, sum = m; i; --i)
	{
		num[i] = sum - p[i][sum];
		sum = p[i][sum];
	}
	for(int i = 1; i <= n; ++i)
		cout << i << " " << num[i] << endl;
	return 0;
}
