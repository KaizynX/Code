#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int Maxn = 100 + 7;
const int INF = 0x3f3f3f3f;

int n, sp, ep, ans = INF;
vector<int> v[Maxn];
int now[Maxn]; // now is trun to n'th place
bool vis[Maxn];

void dfs(int cur, int depth)
{
	if(cur == ep)
	{
		ans = min(ans,depth);
		return;
	}
	if(depth >= ans) return;
	int nexp, tmp;
	vis[cur] = true;
	tmp = now[cur];
	nexp = v[cur][tmp];
	if(!vis[nexp]) dfs(nexp,depth);
	for(int i = 1; i <= v[cur].front(); ++i)
	{
		if(i == tmp) continue;
		now[cur] = i; // turn the road
		nexp = v[cur][i];
		dfs(nexp,depth + 1);
		now[cur] = tmp; // return the former situation
	}
	vis[cur] = false;
}

int main()
{
	int tmp, k;
	memset(vis,0,sizeof vis);
	cin >> n >> sp >> ep;
	for(int i = 1; i <= n; ++i)
	{
		cin >> k;
		v[i].push_back(k);
		for(int j = 0; j < k; ++j)
		{
			cin >> tmp;
			v[i].push_back(tmp);
		}
		now[i] = 1;
	}
	dfs(sp,0);
	cout << (ans == INF ? -1 : ans) << endl;
	return 0;
}
