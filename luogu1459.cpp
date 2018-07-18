#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int Maxn = 1000 + 7;

int n, ans;
int a[Maxn];
int pos[4], cnt[4];
int f[4][4];
// f[i][j] the num of 'i' in area[j]

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d",a+i);
		cnt[a[i]]++;
	}
	for(int i = 1; i <= 3; ++i)
	{
		pos[i] = pos[i-1] + cnt[i];
	}
	for(int i = 1, now = 1; i <= n; ++i)
	{
		if(i > pos[now]) ++now;
		f[ a[i] ][ now ] ++;
	}
	// first exchange which need only one time
	// (1,2)(1,3)(2,3)
	for(int i = 1; i < 3; ++i)
	{
		for(int j = i + 1; j <= 3; ++j)
		{
			// printf("%d %d %d %d\n",i,j,f[i][j],f[j][i]);
			int tmp = min(f[i][j],f[j][i]);
			f[i][j] -= tmp;
			f[j][i] -= tmp;
			ans += tmp;
		}
	}
	// then ... depend on RP
	int tmp = 0;
	for(int i = 1; i < 3; ++i)
	{
		for(int j = i + 1; j <= 3; ++j)
		{
			tmp += f[i][j] + f[j][i];
		}
	}
	ans += tmp / 3 * 2;
	cout << ans << endl;
	return 0;
}
