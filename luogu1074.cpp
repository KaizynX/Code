#include <iostream>
#include <cstdio>
#include <queue>
#include <bitset>

using namespace std;

int ans, rest;
bool b[10][10][10];
bool vis[10][10];
int mark[10][10];
int a[10][10];

struct Node
{
	int x, y, choice;
	Node(){}
	Node(int x, int y, int choice):x(x), y(y), choice(choice) {}

	bool operator < (const Node &b) const
	{
		return choice > b.choice;
	}
};

queue<Node> q;

inline void init(); // init the mark
inline bool judge(int, int, int); // wether there can put this
inline void change(int, int, int, int); // set flag
inline int cal_v(); // calc the value of whole picture
inline int cal_c(int, int); // calc the choice of a pos

void dfs(int flag)
{
	if(!flag) {
		ans = max(ans, cal_v());
		return;
	}

	Node cur = q.top(); q.pop();
	while(vis[cur.x][cur.y]) {
		cur = q.top();
		q.pop();
	}

	for(int i = 1; i <= 9; ++i)
	{
		if(b[cur.x][cur.y][i]) continue;
		if(!judge(cur.x, cur.y, i)) continue;
		a[cur.x][cur.y] = i;
		change(cur.x, cur.y, i, 1);
		vis[cur.x][cur.y] = true;
		dfs(flag-1);
		change(cur.x, cur.y, i, -1);
		vis[cur.x][cur.y] = false;
	}
}

int main()
{
	init();
	for(int i = 1; i <= 9; ++i)
		for(int j = 1; j <= 9; ++j)
		{
			scanf("%d", &a[i][j]);
			if(!a[i][j]) {
				++rest; continue;
			}
			vis[i][j] = true;
			if(!judge(i, j, a[i][j])) {
				puts("-1"); return 0;
			}
			change(i, j, a[i][j], 1);
		}
	for(int i = 1; i <= 9; ++i)
		for(int j = 1; j <= 9; ++j)
			if(!a[i][j])
				q.push(Node(i, j, cal_c(i, j)));
	dfs(rest);
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

inline bool judge(int x, int y, int num)
{
	for(int i = 1; i <= 9; ++i)
		if(b[x][i][num] || b[i][y][num]) return false;
	if(x == y)
		for(int i = 1; i <= 9; ++i)
			if(b[i][i][num]) return false;
	if(x + y == 10)
		for(int i = 1; i <= 9; ++i)
			if(b[i][10-i][num]) return false;
	return true;
}

inline void change(int x, int y, int num, int v)
{
	for(int i = 1; i <= 9; ++i)
	{
		b[x][i][num] += v;
		b[i][y][num] += v;
	}
	if(x == y)
		for(int i = 1; i <= 9; ++i)
			b[i][i][num] += v;
	if(x + y == 10)
		for(int i = 1; i <= 9; ++i)
			b[i][10-i][num] += v;
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
	int res = 0;
	for(int i = 1; i <= 9; ++i)
		if(!b[x][y][i]) ++res;
	return res;
}
