#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 60;
const int Maxm = 500;
const char Square[10][10]={
"..+---+",
"./   /|",
"+---+ |",
"|   | +",
"|   |/.",
"+---+.."                 };

int n, m, a[Maxn][Maxn], width, height;
char f[Maxm][Maxm];

inline void draw(int xi, int yi)
{
	for(int x = xi-5, i = 0; x <= xi; ++x, ++i)
		for(int y = yi, j = 0; y <= yi+6; ++y, ++j)
			if(f[x][y] == '.') f[x][y] = Square[i][j];
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			height = max(height, 3*a[i][j]+2*(m-i+1)+1);
		}
	width = 4*n+2*m+1;
	memset(f, '.', sizeof f);
	for(int i = m; i; --i)
		for(int j = n; j; --j)
			for(int h = a[i][j]; h; --h)
				draw(height-(3*(h-1)+2*(m-i)), 4*(j-1)+1+2*(m-i));
	for(int i = 1; i <= height; ++i)
	{
		for(int j = 1; j <= width; ++j)
			putchar(f[i][j]);
		putchar('\n');
	}
	return 0;
}
