#include <bits/stdc++.h>

using namespace std;

struct BigInteger
{
	const static int N = 205;
	const static int BASE = 1e4;
	const static int WIDTH = 4;

	int v[N], len;

	BigInteger(){ memset(v, 0, sizeof v); len = 1; }

	BigInteger operator = (const string &str)
	{
		len = (str.length()-1)/WIDTH+1;
		int head = max(0, (int)str.length()-WIDTH), tail = str.length();
		for(int i = 1; i <= len; ++i)
		{
			sscanf(str.substr(head, tail-head).c_str(), "%d", &v[i]);
			head = max(head-WIDTH, 0);
			tail -= WIDTH;
		}
		return *this;
	}

	BigInteger operator - (const BigInteger &b) const
	{
		BigInteger res = *this;
		for(int i = 1; i <= b.len; ++i)
			res.v[i] -= b.v[i];
		for(int i = 1; i <= len; ++i)
			if(res.v[i] < 0)
			{
				res.v[i] += BASE;
				res.v[i+1] --;
			}
		while(res.len > 1 && res.v[res.len] == 0) res.len--;
		return res;
	}

	BigInteger operator -= (const BigInteger &b) { return *this = *this-b; }
}a, b;

istream& operator >> (istream &is, BigInteger &big)
{
	string str;
	if(is >> str) big = str;
	return is;
}

ostream& operator << (ostream &os, BigInteger &big)
{
	os << big.v[big.len];
	for(int i = big.len-1; i; --i)
	{
		char buf[10];
		sprintf(buf, "%04d", big.v[i]);
		for(int j = 0, sz = strlen(buf); j < sz; ++j)
			os << buf[j];
	}
	return os;
}

int main()
{
	cin >> a >> b;
	a -= b;
	cout << a << endl;
	return 0;
}
