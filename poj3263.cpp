#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int Maxn = 1e6 + 7;

int N, I, H, R;
int s[Maxn];
map < pair<int,int>,bool > vis;

inline int getint();

int main()
{
	N = getint(); I = getint(); H = getint(); R = getint();
	for(int i = 0, a, b; i < R; ++i)
	{
		a = getint(); b =getint();
		if(a > b) swap(a,b);
		if(vis.count( make_pair(a,b) )) continue;
		// (a,b) - 1
		--s[a+1]; ++s[b];
		vis.insert( make_pair( make_pair(a,b), true));
	}
	for(register int i = 1, cur = H; i <= N; ++i)
	{
		cur += s[i];
		printf("%d\n",cur);
	}
	return 0;
}

inline int getint()
{
	char c;
	while( (c = getchar()) < '0' || c > '9');
	int res = c - '0';
	while( (c = getchar()) >= '0' && c <= '9') res = res * 10 + c - '0';
	return res;
}
