#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int Maxn = 6e3 + 7;

int n;
int a[Maxn], f[Maxn][2];
// f[][0] not choose
// f[][1] choose it
vector<int> son[Maxn];
bool not_root[Maxn];

/*
 * f[father][0] = sum[ max(f[son][0], f[son][1]) ]
 * f[father][1] = a[father] + sum[ f[son][0] ]
 */

void DP(int cur)
{
	f[cur][1] = a[cur];
	int num = son[cur].size();
	for(int i = 0, child; i < num; ++i)
	{
		child = son[cur][i];
		DP(child);
		f[cur][0] += max(f[child][0], f[child][1]);
		f[cur][1] += f[child][0];
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	int x, y;
	while(scanf("%d%d", &x, &y) && x && y) // x is y's son
	{
		son[y].push_back(x);
		not_root[x] = true;
	}
	int root;
	for(int i = 1; i <= n; ++i)
		if(!not_root[i])
		{
			root = i;
			break;
		}
	DP(root);
	printf("%d\n", max(f[root][0], f[root][1]));
	return 0;
}
