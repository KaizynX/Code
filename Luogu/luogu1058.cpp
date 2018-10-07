#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 60;
const int Maxm = 500;

int n, m, a[Maxn][Maxn], width, height;
int f[Maxm][Maxm];

inline char change(int v)
{
// '.' 0, '+' 1, '-' 2, '|' 3, '/' 4, ' ' 5
	if(v == 0) return '.';
	else if(v == 1) return '+';
	else if(v == 2) return '-';
	else if(v == 3) return '|';
	else if(v == 4) return '/';
	else return ' ';
}

inline void draw(int x, int y)
{
	if(!f[x][y]) f[x][y] = 1;
	if(!f[x][y+4]) f[x][y+4] = 1;
	if(!f[x-3][y]) f[x-3][y] = 1;
	if(!f[x-3][y+4]) f[x-3][y+4] = 1;
	if(!f[x-2][y+6]) f[x-2][y+6] = 1;
	if(!f[x-5][y+6]) f[x-5][y+6] = 1;
	if(!f[x-5][y+2]) f[x-5][y+2] = 1;
	for(int i = 1; i <= 3; ++i)
	{
		if(!f[x][y+i]) f[x][y+i] = 2;
		if(!f[x-3][y+i]) f[x-3][y+i] = 2;
		if(!f[x-5][y+i+2]) f[x-5][y+i+2] = 2;
		if(!f[x-i][y]) f[x-i][y] = 3;
		if(!f[x-i][y+4]) f[x-i][y+4] = 3;
		if(!f[x-i-2][y+6]) f[x-i-2][y+6] = 3;
		for(int j = 1; j <= 2; ++j)
			if(!f[x-j][y+i]) f[x-j][y+i] = 5;
		if(!f[x-4][y+i+1]) f[x-4][y+i+1] = 5;
	}
	if(!f[x-2][y+5]) f[x-2][y+5] = 5;
	if(!f[x-3][y+5]) f[x-3][y+5] = 5;
	if(!f[x-4][y+1]) f[x-4][y+1] = 4;
	if(!f[x-4][y+5]) f[x-4][y+5] = 4;
	if(!f[x-1][y+5]) f[x-1][y+5] = 4;
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			scanf("%d", &a[i][j]);
			height = max(height, 3*a[i][j]+2*(m-i+1)+1);
		}
	}
	width = 4*n+2*m+1;
#ifdef DEBUG
	printf("width:%d height:%d\n", width, height);
#endif
	for(int i = m; i; --i)
		for(int j = n; j; --j)
			for(int h = a[i][j]; h; --h)
				draw(height-(3*(h-1)+2*(m-i)), 4*(j-1)+1+2*(m-i));
	for(int i = 1; i <= height; ++i)
	{
		for(int j = 1; j <= width; ++j)
			putchar(change(f[i][j]));
		putchar('\n');
	}
	return 0;
}
