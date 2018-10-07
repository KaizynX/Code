#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
// #define DEBUG

using namespace std;

const int Maxn = 30;

int n;
char s[3][Maxn];
int a[3][Maxn];
int v[Maxn], p[Maxn];
bool used[Maxn];

void dfs(int cur, int line)
{
	if(cur < 0)
	{
		for(int i = 0; i <= n-2; ++i) printf("%d ", v[i]);
		printf("%d\n", v[n-1]);
		exit(0);
	}

	if(line == 2)
	{
		int &now = v[a[line][cur]],
			tmp = v[a[0][cur]] + v[a[1][cur]] + p[cur+1];
#ifdef DEBUG
			printf("%d %d %d %d %d\n", cur, now, v[a[0][cur]], v[a[1][cur]], p[cur+1]);
#endif
		if(now != -1)
		{
			if(now != tmp%n) return;
			else
			{
				p[cur] = tmp/n;
				dfs(cur-1, 0);
			}
		}
		else
		{
			now = tmp % n;
			p[cur] = tmp / n;
			dfs(cur-1, 0);
			now = -1;
			p[cur] = 0;
		}
	}
	else
	{
		int &now = v[a[line][cur]];
		if(now != -1) dfs(cur, line+1);
		else
		{
			for(int i = 0; i < n; ++i)
			{
				if(used[i]) continue;
				now = i;
				used[i] = true;
				dfs(cur, line+1);
				now = -1;
				used[i] = false;
			}
		}
	}
}

int main()
{
	memset(v, -1, sizeof v);
	scanf("%d", &n);
	scanf("%s%s%s", s[0], s[1], s[2]);
	for(int i = 0; i < 3; ++i)
		for(int j = 0; j < n; ++j)
			a[i][j] = s[i][j] - 'A';
	dfs(n-1, 0);
	return 0;
}
