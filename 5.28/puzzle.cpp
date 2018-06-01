#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 107;

int n;
bool m[Maxn][Maxn];

inline bool solve(int x, int y)
{
	// we are sure that x+2 & y-1 & y+1 are in the range of m[][]
	m[x][y] = false; // top
	if(!m[x+1][y]) return false; // mid
	m[x+1][y] = false;
	if(!m[x+1][y-1]) return false; // left
	m[x+1][y-1] = false;
	if(!m[x+1][y+1]) return false; // right
	m[x+1][y+1] = false;
	if(!m[x+2][y]) return false; // bottom
	m[x+2][y] = false;
	return true;
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	char c;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
		{
			cin >> c;
			if(c == '#') m[i][j] = true;
			// else m[i][j] = false;
		}
	// if we scan from up to down and left to right
	// we must first meet a '#' which is the top of a %#$(&
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(m[i][j])
				if(!solve(i,j))
				{
					printf("NO\n");
					return 0;
				}
	printf("YES\n");
	return 0;
}
