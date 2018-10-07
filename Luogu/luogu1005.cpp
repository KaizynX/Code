#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define DEBUG

using namespace std;

const int Maxn = 80 + 7;

struct BigInteger
{
	const static int BASE = 1e4;
	const static int WIDTH = 4;

	vector<int> v;

	BigInteger(){}
	BigInteger(long long num) { *this = num; }

	BigInteger operator = (long long num)
	{
		v.clear();
		do{
			v.push_back(static_cast<int>(num % BASE));
			num /= BASE;
		} while(num);
		return *this;
	}

	bool operator < (const BigInteger &b) const
	{
		if(v.size() != b.v.size()) return v.size() < b.v.size();
		for(int i = v.size()-1; i >= 0; --i)
			if(v[i] != b.v[i])
				return v[i] < b.v[i];
		return false; //  ==
	}

	BigInteger operator + (const BigInteger &b) const
	{
		BigInteger res;
		res.v.clear();
		int g = 0;
		for(unsigned i = 0; ; ++i)
		{
			if(g == 0 && i >= v.size() && i >= b.v.size()) break;
			if(i < v.size()) g += v[i];
			if(i < b.v.size()) g += b.v[i];
			res.v.push_back(g % BASE);
			g /= BASE;
		}
		return res;
	}
	BigInteger operator += (const BigInteger &b) { *this = *this + b; return *this; }

	BigInteger operator * (const BigInteger &b) const
	{
		BigInteger res;
		res.v.resize(v.size()+b.v.size(), 0);
		for(unsigned i = 0; i < v.size(); ++i)
		{
			for(unsigned j = 0; j < b.v.size(); ++j)
			{
				res.v[i+j] += v[i] * b.v[j];
				res.v[i+j+1] += res.v[i+j] / BASE;
				res.v[i+j] %= BASE;
			}
		}
		if(res.v.back() == 0) res.v.pop_back();
		return res;
	}
	BigInteger operator *= (const BigInteger &b) { *this = *this * b; return *this; }
};

int n, m;
int a[Maxn];
BigInteger ans, p, maxf, f[Maxn][Maxn];
// f[l][r] ==> the max value of taking l left num and r right num

template <typename T> inline T max(T &a, T &b) { return a < b ? b : a; }
ostream& operator << (ostream &os, BigInteger &big)
{
	os << big.v.back();
	for(int i = big.v.size()-2; i >= 0; --i)
	{
		char buf[5];
		sprintf(buf, "%04d", big.v[i]);
		for(unsigned j = 0; j < 4; ++j)
			os << buf[j];
	}
	return os;
}

int main()
{
	scanf("%d%d", &n, &m);
	while(n--)
	{
		for(int i = 1; i <= m; ++i) scanf("%d", a+i);
		memset(f, 0, sizeof f);
		p = 1; // 2 ^ 0
		for(int k = 1; k <= m; ++k) // take k number
		{
			p *= 2; // p = 2 ^ k
			for(int l = 0, r; l <= k; ++l)
			{
				r = k - l;
				if(l - 1 >= 0) f[l][r] = max(f[l][r], f[l-1][r]+p*a[l]);
				if(r - 1 >= 0) f[l][r] = max(f[l][r], f[l][r-1]+p*a[m-r+1]);
#ifdef DEBUG
				cout << l << " " << r << " " << f[l][r] << endl;
#endif
			}
		}
		maxf = 0;
		for(int l = 0; l <= m; ++l) maxf = max(maxf, f[l][m-l]);
		ans += maxf;
#ifdef DEBUG
		cout << ans << endl;
#endif
	}
	cout << ans << endl;
	return 0;
}
