#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 993244853;

int n, ansi;
long long C[Maxn], inv[Maxn], sf[Maxn], ansv;

template <typename T> inline void read(T &);
void write(int);

inline void init()
{
	// sf[n] = (n-1)(sf[n-1]+sf[n-2])
	sf[0] = 1; sf[1] = 0; sf[2] = 1;
	for(int i = 3; i <= n; ++i)
		sf[i] = (sf[i-1]+sf[i-2])%MOD*(i-1)%MOD;

	inv[1] = 1;
	for(int i = 2; i <= n; ++i)
		inv[i]= (MOD-MOD/i)*inv[MOD%i]%MOD;

	C[0] = 1;
	for(int i = 1; i <= n; ++i)
		C[i] = C[i-1]*(n-i+1)%MOD*inv[i]%MOD;
}

int main()
{
	read(n);
	init();
	for(int i = 0, c; i <= n; ++i)
	{
		read(c);
		long long cur = sf[i]*C[i]%MOD*c%MOD;
		if(cur > ansv)
		{
			ansi = i;
			ansv = cur;
		}
	}
	write((int)ansv); putchar('\n');
	for(int i = 1; i <= n-ansi; ++i)
		write(i), putchar(' ');
	for(int i = n-ansi+1, flag = 1; i <= n-3*(ansi&1); ++i, flag = -flag)
		write(i+flag), putchar(' ');
	if(ansi&1)
	{
		write(n-1); putchar(' ');
		write(n);   putchar(' ');
		write(n-2);
	}
	putchar('\n');
	return 0;
}

template <typename T> inline void read(T &x)
{
	char c; T tag = 1;
	while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
	x = c-'0';
	while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}

void write(int x)
{
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
