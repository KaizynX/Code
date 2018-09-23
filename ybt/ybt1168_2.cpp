#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 300;

struct BigInteger
{
	int len, v[Maxn];

	BigInteger(){ len = 1; memset(v, 0, sizeof v); }
	BigInteger(const string &str) { *this = str; }

	BigInteger operator = (const string &str)
	{
		int pos = 0;
		while(pos < str.length() && str[pos] == '0') pos++;
		if(pos == str.length()) // 0
		{
			len = 1;
			return *this;
		}

		len = 0;
		memset(v, 0, sizeof v);
		for(int i = str.length()-1; i >= pos; --i)
			v[++len] = str[i]-'0';
		return *this;
	}

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

istream& operator >> (istream &is, BigInteger &big)
{
	string str;
	if(is >> str)
		big = str;
	return is;
}

inline void write(BigInteger &big)
{
	for(int i = big.len; i; --i)
		putchar(big.v[i]+'0');
	putchar('\n');
}

int main()
{
	cin >> a >> b;
	a += b;
	write(a);
	return 0;
}
