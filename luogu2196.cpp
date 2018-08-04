#include <iostream>

using namespace std;

const int Maxn = 30;

int n, a[Maxn], e[Maxn][Maxn], f[Maxn], nex[Maxn];

int main()
{
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			cin >> e[i][j];
	for(int i = n; i >= 1; --i)
	{
		for(int j = i+1; j <= n; ++j)
		{
			if(e[i][j] && f[j] > f[i])
			{
				nex[i] = j;
				f[i] = f[j];
			}
		}
		f[i] += a[i];
	}
	int cur = 1, ans;
	for(int i = 2; i <= n; ++i)
		if(f[cur] < f[i])
			cur = i;
	ans = f[cur];
	cout << cur;
	while(nex[cur]) cout << " " << (cur = nex[cur]);
	cout << endl << ans << endl;
	return 0;
}
