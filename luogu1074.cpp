#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int ans = -1, rest;
int b[10][10][10];
bool vis[10][10];
int mark[10][10];
int a[10][10];
vector<pair<int,int> > v;

inline void init(); // init the mark
inline void change(int, int, int, int); // set flag
inline int cal_v(); // calc the value of whole picture
inline int cal_c(int, int);

void dfs(int flag)
{
	if(!flag) 
	{
		ans = max(ans, cal_v());
		return;
	}
	
	// find the one
	int minx, miny, minc = 10;
	for(int i = 0, tmp, x, y, edge = v.size(); i < edge; ++i)
	{
		x = v[i].first; y = v[i].second;
		if(vis[x][y]) continue;
		if( (tmp = cal_c(x, y)) < minc)
			minx = x, miny = y, minc = tmp;
		if(minc <= 1) break;
	}
	// search it
	vis[minx][miny] = true;
	for(int i = 1; i <= 9; ++i)
	{
		if(b[minx][miny][i]) continue;
		change(minx, miny, i, 1);
		a[minx][miny] = i;
		dfs(flag-1);
		change(minx, miny, i, -1);
	}
	vis[minx][miny] = false;
}

int main()
{
	init();
	for(int i = 1; i <= 9; ++i)
		for(int j = 1; j <= 9; ++j)
		{
			scanf("%d", &a[i][j]);
			if(!a[i][j]) {
				++rest;
				v.push_back(make_pair(i, j));
				continue;
			}
			vis[i][j] = true;
			if(b[i][j][a[i][j]]) {
				puts("-1"); return 0;
			}
			change(i, j, a[i][j], 1);
		}
	dfs(rest);
	printf("%d\n", ans);
	return 0;
}

inline void init()
{
	for(int i = 1; i <= 9; ++i)
		mark[i][1] = mark[i][9] = mark[1][i] = mark[9][i] = 6;
	for(int i = 2; i <= 8; ++i)
		mark[i][2] = mark[i][8] = mark[2][i] = mark[8][i] = 7;
	for(int i = 3; i <= 7; ++i)
		mark[i][3] = mark[i][7] = mark[3][i] = mark[7][i] = 8;
	for(int i = 4; i <= 6; ++i)
		mark[i][4] = mark[i][6] = mark[4][i] = mark[6][i] = 9;
	mark[5][5] = 10;
}

inline void change(int x, int y, int num, int v)
{
	// 横竖
	for(int i = 1; i <= 9; ++i)
	{
		b[x][i][num] += v;
		b[i][y][num] += v;
	}
	/* 对角线
	if(x == y)
		for(int i = 1; i <= 9; ++i)
			b[i][i][num] += v;
	if(x + y == 10)
		for(int i = 1; i <= 9; ++i)
			b[i][10-i][num] += v;
	*/
	// 小九格
	for(int i = (x-1)/3*3+1; i <= (x-1)/3*3+3; ++i)
		for(int j = (y-1)/3*3+1; j <= (y-1)/3*3+3; ++j)
			b[i][j][num] += v;
}

inline int cal_v()
{
	int res = 0;
	for(int i = 1; i <= 9; ++i)
		for(int j = 1; j <= 9; ++j)
			res += mark[i][j] * a[i][j];
	return res;
}

inline int cal_c(int x, int y)
{
	int res = 9;
	for(int i = 1; i <= 9; ++i)
		if(b[x][y][i]) --res;
	return res;
}
