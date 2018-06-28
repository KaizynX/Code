#include <iostream>
#include <cstdio>
#include <cstring>
#define DEBUG

using namespace std;

const int Maxn = 47;
const int Maxk = 10;

int n, k;
struct BigInteger
{
	static const int BASE = 1e4;

	int v[Maxn], len;
	
	BigInteger(){ memset(v, 0, sizeof v); len = 0; }
	BigInteger(const string &str) { *this = str; }

	BigInteger operator = (const string &str)
	{
		len = 0;
		for(int i = str.length()-1; i >= 0; --i)
			v[++len] = str[i]-'0';
		return *this;
	}

	BigInteger operator * (const BigInteger &b) const
	{
		BigInteger res;
		res.len = len + b.len;
		for(int i = 1; i <= len; ++i)
			for(int j = 1; j <= b.len; ++j)
				res.v[i+j-1] += v[i] * b.v[j];
		for(int i = 1; i <= len + b.len; ++i)
		{
			res.v[i+1] += res.v[i] / 10;
			res.v[i] %= 10;
		}
		while(!res.v[res.len]) --res.len;
		return res;
	}

	bool operator < (const BigInteger &b) const
	{
		if(len != b.len) return len < b.len;
		for(int i = len; i; --i)
			if(v[i] != b.v[i]) return v[i] < b.v[i];
		return false;
	}

} f[Maxn][Maxn][Maxk]; 
// f[l][r][k] maxv of [l][r] divide to k pieces

// template <typename T> inline T max(const T &a, const T &b) const { return a < b ? b : a; }

ostream &operator << (ostream &os, const BigInteger big)
{
	for(int i = big.len; i; --i)
		os << big.v[i];
	return os;
}

int main()
{
	string num;
	cin >> n >> k >> num;
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
			f[i][j][1] = num.substr(i, (j-i+1));
	// dp
	for(int ki = 2; ki <= k; ++ki)
		for(int i = 0; i < n-ki+1; ++i)
			for(int j = i+ki-1; j < n; ++j)
				for(int mid = i; mid < j; ++mid)
				{
					f[i][j][ki] = max(f[i][j][ki], f[i][mid][ki-1] * f[mid+1][j][1]);
#ifdef DEBUG
					cout << i << " " << j << " " << ki << " " << mid << " " << f[i][j][ki] << endl;
#endif
				}
	
	cout << f[0][n-1][k] << endl;
	return 0;
}
