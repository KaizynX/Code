#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, s, ans, flag;
int a[Maxn], du[Maxn];
int ver[Maxn], fir[Maxn], nex[Maxn];
vector<int> v;

void dfs(int cur)
{
	v.push_back(0);
	int tmp = flag;
	for(int i = flag, _size = v.size(); i < _size; ++i)
	{
		if(v[i]+a[cur] == s) ans++, flag++;
		else if(v[i]+a[cur] > s) flag++;
		else v[i] += a[cur];
	}
	for(int i = fir[cur]; i; i = nex[i])
		dfs(ver[i]);
	for(int i = flag, _size = v.size(); i < _size; ++i)
		v[i] -= a[cur];
	flag = tmp;
	/*
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		if((*it += a[cur]) == s) ++ans;
	for(int i = fir[cur]; i; i = nex[i])
		dfs(ver[i]);
	for(vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		*it -= a[cur];
	*/
	v.pop_back();
}

int main()
{
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for(int i = 1, x, y; i < n; ++i)
	{
		scanf("%d%d", &x, &y);
		ver[i] = y;
		nex[i] = fir[x];
		fir[x] = i;
		du[y]++;
	}
	// find the root
	for(int i = 1; i <= n; ++i)
	{
		if(!du[i])
		{
			dfs(i);
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
