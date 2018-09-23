#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 300;

struct BigInteger
{
	int len, v[Maxn];
	BigInteger(){ len = 1; memset(v, 0, sizeof v); }
	BigInteger operator + (const BigInteger &b) const
	{
		BigInteger res;
		res.len = max(len, b.len);
		for(int i = 1; i <= res.len; ++i)
		{
			res.v[i] += v[i]+b.v[i];
			res.v[i+1] += res.v[i]/10;
			res.v[i] %= 10;
		}
		while(res.v[res.len+1]) res.len++;
		return res;
	}
	BigInteger operator += (const BigInteger &b) { return *this = *this+b; }
} a, b;

inline void read(BigInteger &big)
{
	int &len = big.len; char c;
	while((c=getchar()) < '0' || c > '9');
	big.v[len = 1] = c-'0';
	while((c=getchar()) >= '0' && c <= '9')
		big.v[++len] = c-'0';
	// the 0 before the num
	while(len > 1 && !big.v[len]) len--;
}

inline void write(BigInteger &big)
{
	for(int i = big.len; i; --i)
		putchar(big.v[i]+'0');
	putchar('\n');
}

int main()
{
	read(a); read(b);
	a += b;
	write(a);
	return 0;
}
