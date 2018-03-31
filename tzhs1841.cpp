#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>

#define DEBUG

using namespace std;

const int Maxm = 100 + 7;
const int Maxn = 500 + 7;

int m, n, ans;
bool a[Maxn][Maxn];
bool vis[Maxn];
int dis[Maxn],num;

int bfs()
{
	int now_point, now_dis;
	queue<int> q_point, q_dis;
	q_point.push(1);
	q_dis.push(-1); // you in the first car and to the first place is that change 0 time
	vis[1] = true;

	while(!q_point.empty())
	{
		now_point = q_point.front();
		now_dis = q_dis.front();
		q_point.pop();
		q_dis.pop();

		for(int i = 1; i <= n; ++i)
		{
			if(!a[now_point][i] || vis[i])
				continue;

			//find the result
			if(i == n) return now_dis + 1;
			// push
			vis[i] = true;
			q_point.push(i);
			q_dis.push(now_dis + 1);
		}

		// vis[now_point] = false;
	}
	return -1;
}

int main()
{
	string tmp;
	memset(a,0,sizeof a);
	getline(cin,tmp);
	stringstream s_tmp(tmp);
	s_tmp >> m >> n;

	if(1 == n) // emmm
	{
		printf("0\n");
		return 0;
	}

	for(int k = 0; k < m; ++k) // k lines datas
	{
		num = 0;
		getline(cin,tmp);
		stringstream sio(tmp);
		while(sio >> dis[++num]); 

		for(int i = 1; i < num; ++i)
		{
			for(int j = i + 1; j <= num; ++j)
			{
				a[ dis[i] ][ dis[j] ] = true;
			}
		}
	}
#ifdef DEBUG
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
#endif
	ans = bfs();
	if(ans == -1) printf("NO\n");
	else printf("%d\n",ans);
	return 0;
}
