#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxk = 110;

int k, ans;
string n;

struct Bigint
{
	int v[Maxk];

	Bigint(){ memset(v, 0, sizeof v); }
	Bigint(const string &str) { *this = str; }

	Bigint operator = (const string &str)
	{
		for(int i = str.length()-1, j = 1; i >= 0 && j <= k; --i, ++j)
			v[j] = str[i]-'0';
		return *this;
	}

	bool operator != (const Bigint &b) const
	{
		for(int i = 1; i <= k; ++i)
			if(v[i] != b.v[i]) return true;
		return false;
	}

	Bigint operator * (const Bigint &b) const
	{
		Bigint res;
		for(int i = 1, now; i <= k; ++i)
			for(int j = 1; j <= k; ++j)
			{
				now = i+j-1;
				if(now <= k) res.v[now] += v[i]*b.v[j];
			}
		for(int i = 1; i <= k; ++i)
		{
			res.v[i+1] += res.v[i]/10;
			res.v[i] %= 10;
		}
		return res;
	}

	Bigint operator *= (const Bigint &b) { return *this = *this*b; }

} cur, fir;

inline Bigint pow(Bigint b, int p)
{
	Bigint res = b;
	while(p)
	{
		if(p&1) res *= b;
		p >>= 1;
		b *= b;
	}
	return res;
}

int main()
{
	cin >> n >> k;
	fir = n;
	for(int i = 1; i <= k; ++i)
	{
		for(int j = 1; j <= 10; ++j)
		{
			;
		}
	}
	return 0;
}
