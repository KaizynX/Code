#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>
#include <queue>

#define DEBUG

using namespace std;

const int Maxm = 100 + 7;
const int Maxn = 500 + 7;
const int INF = 0x3f3f3f3f;

int m, n, ans;
int a[Maxn][Maxn];
int dis[Maxn],num;

int main()
{
	string tmp;
	memset(a,0x3f,sizeof a);
	getline(cin,tmp);
	stringstream s_tmp(tmp);
	s_tmp >> m >> n;

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
	for(int i = 1; i <= n; ++i)
		a[i][i] = 0;
#ifdef DEBUG
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			cout << a[i][j] << " ";
		cout << endl;
	}
#endif
	// floyd
	for(int k = 1; k <= n; ++k)
	{
		for(int i = 1; i <= n; ++i)
		{
			for(int j = 1; j <= n; ++j)
			{
				if(a[i][k] + a[k][j] < a[i][j])
					a[i][j] = a[i][k] + a[k][j];
			}
		}
	}
	if(a[1][n] == INF) printf("NO\n");
	else printf("%d\n",a[1][n] - 1);
	return 0;
}
