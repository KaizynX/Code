#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 10000 + 7;

int n, ans;
int t[Maxn], f[Maxn];
int a[Maxn][107];
int du[Maxn];

int dfs(int cur)
{
	if(f[cur] != -1) return f[cur];

	f[cur] = t[cur];
	for(int i = 1; i <= a[cur][0]; ++i)
	{
		f[cur] = max(f[cur],dfs(a[cur][i]) + t[cur]);
	}
	return f[cur];
}

int main()
{
	memset(f,-1,sizeof f); // -1 refer to not visited
	int now, tmp;
	cin >> n;
	for(int i = 1; i <= n; ++i)
	{
		cin >> now >> tmp;
		t[now] = tmp;
		int &num = a[now][0];
		while(cin >> tmp && tmp)
		{
			a[now][++num] = tmp;
			++du[tmp];
		}
	}
	for(int i = 1; i <= n; ++i)
	{
		if(!du[i])
			ans = max(ans,dfs(i));
	}
	cout << ans << endl;
	return 0;
}
