#include <iostream>
#include  <algorithm>

using namespace std;

const int Maxn = 100 + 7;

int n, ans;
int a[Maxn * 2];
int f[Maxn * 2][Maxn * 2]; // max_ans < 2.1e9

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}

	// memset(f,0,sizeof f);
	for(int len = 2; len <= n; ++len) // 1,2,3 --> (1,2)(2,3)(3,1) --> 1,2,3,1 
	{
		for(int i = 1, j = i + len; j <= n<<1; ++i, j = i + len)
		{
			for(int k = i + 1; k < j; ++k) // (a[i],a[k]) & (a[k],a[j])
			{
				f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i]*a[k]*a[j]);
			}
		}
	}

	for(int i = 1; i <= n; ++i)
		ans = max(ans, f[i][i + n]);
	cout << ans << endl;
	return 0;
}
