#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

int p;

struct BigInteger
{
	static const int SIZE = 501;
	int d[SIZE];

	BigInteger() { memset(d,0,sizeof d); }
	BigInteger(int n) { *this = n; }

	BigInteger operator = (int n)
	{
		memset(d,0,sizeof d);
		d[1] = n;
		return *this;
	}
	
	BigInteger operator * (const BigInteger &b) const
	{
		BigInteger res;
		for(int i = 1; i <= 500; ++i)
			for(int j = 1; j <= 500; ++j)
				res.d[i+j-1] += d[i] * b.d[j];

		for(int i = 1; i <= 500; ++i)
		{
			res.d[i+1] += res.d[i] / 10;
			res.d[i] %= 10;
		}
		return res;
	}

	BigInteger operator *= (const BigInteger &b) { *this = *this * b; return *this; }

}ans, tmp;

ostream &operator << (ostream &out, BigInteger &big)
{
	for(int i = 500; i >= 1; --i)
	{
		if(i != 500 && i % 50 == 0) out << endl << big.d[i];
		else out << big.d[i];
	}
	return out;
}

int main()
{
	cin >> p;
	// lg(2 ^ p) = lg(2) * p
	cout << static_cast<int>(log10(2) * p + 1) << endl;

	ans = 1;
	tmp = 2; // 2 ^ 1
	while(p)
	{
		/*
		if(p & 1) ans *= tmp;
		p >>= 1;
		tmp *= tmp;
		*/
		if(p & 1) ans = ans * tmp;
		p >>= 1;
		tmp = tmp * tmp;
	}

	ans.d[1] -= 1;
	cout << ans << endl;

	return 0;
}
