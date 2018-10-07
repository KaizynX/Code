#include <bits/stdc++.h>

using namespace std;

const int Maxn = 507;

int n, m;
int a[Maxn][Maxn];

inline void read(int&);
void write(int);
inline void init();

inline void operate(int ox, int oy, int r, int z)
{
	if(r == 0) return;
	int x[6], y[6], len = r*2+1, tmp[5];
	x[0] = ox-r; y[0] = oy-r;
	x[5] = ox+r; y[5] = oy+r;

	for(int i = 1; i <= len/2; ++i)
	{
		for(int j = i; j <= len-i; ++j)
		{
			x[1] = x[0]+i-1; y[1] = y[0]+j-1;
			x[2] = x[0]+j-1; y[2] = y[5]-i+1;
			x[3] = x[5]-i+1; y[3] = y[5]-j+1;
			x[4] = y[5]-j+1; y[4] = y[0]+i-1;
			for(int i = 1; i <= 4; ++i) tmp[i] = a[x[i]][y[i]];
			for(int i = 1; i <= 4; ++i)
				if(z == 0) a[x[i]][y[i]] = tmp[(i+2)%4+1];
				else a[x[i]][y[i]] = tmp[i%4+1];
		}
	}
}

int main()
{
	int x, y, r, z;
	read(n); read(m);
	init();
	while(m--)
	{
		read(x); read(y); read(r); read(z);
		operate(x, y, r, z);
	}
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			write(a[i][j]), putchar(' ');
		putchar('\n');
	}
	return 0;
}

inline void init()
{
	for(int i = 1, cur = 0; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			a[i][j] = ++cur;
}

inline void read(int &x)
{
    char c;
    while(!isdigit((c=getchar())));
    x = c-'0';
    while(isdigit((c=getchar())))
        x = (x<<1)+(x<<3) + c-'0';
}

void write(int x)
{
    if(x/10) write(x/10);
    putchar(x%10+'0');
}
