#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 100 + 7;

int n,m;
bool vis[Maxn];


int main()
{
	int rest, cur, cnt;
	memset(vis,0,sizeof vis);
	cin >> n >> m;
	rest = n;
	// from 0 to n-1
	cur = 0;
	while(rest)
	{
		// first man said 1
		cnt = 1;
		while(cnt < m)
		{
			// find a man who is not be visited
			while(vis[cur%n]) ++cur;
			// then jump it
			++cur;
			++cnt;
		}
		// find the one we need
		while(vis[cur%n]) ++cur;
		cur %= n;
		vis[cur] = true;
		cout << cur + 1 << " ";
		++cur; // next turn start from the next one
		--rest;
	}
	return 0;
}
