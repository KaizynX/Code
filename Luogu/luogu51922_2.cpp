#include <cstdio>
#include <iostream>

using namespace std;

const int MOD = 1e9+9;

int t, n;

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
	if(x>9) write(x/10);
	putchar(x%10+'0');
}

inline int qpow(long long a, int p)
{
	long long res = 1;
	while(p)
	{
		if(p&1) res = res*a%MOD;
		a = a*a%MOD;
		p >>= 1;
	}
	return (int)res;
}

int main()
{
	read(t);
	while(t--)
	{
		read(n);
		write(qpow(n, n-1));
		putchar('\n');
	}
	return 0;
}
