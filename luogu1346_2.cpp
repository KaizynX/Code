#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int Maxn = 100 + 7;
const int INF = 0x3f3f3f3f;

int n, sp, ep, ans = INF;
int e[Maxn][Maxn];
int dis[Maxn];
bool in_q[Maxn];

void SPFA()
{
	int cur, nexp;
	queue<int> q;
	memset(in_q,0,sizeof in_q);
	memset(dis,-1,sizeof dis);
	q.push(sp);
	in_q[sp] = true;
	dis[sp] = 0;
	while(!q.empty())
	{
		cur = q.front();
		for(int i = 1; i <= e[cur][0]; ++i)
		{
			nexp = e[cur][i];
			if(dis[nexp] == -1 || dis[nexp] > dis[cur] + (i == 1 ? 0 : 1))
			{
				dis[nexp] = dis[cur] + (i == 1 ? 0 : 1);
				if(!in_q[nexp])
				{
					in_q[nexp] = true;
					q.push(nexp);
				}
			}
		}
		q.pop();
		in_q[cur] = false;
	}
}

int main()
{
	cin >> n >> sp >> ep;
	for(int i = 1; i <= n; ++i)
	{
		cin >> e[i][0];
		for(int j = 1; j <= e[i][0]; ++j)
		{
			cin >> e[i][j];
		}
	}
	SPFA();
	cout << dis[ep] << endl;
	return 0;
}

