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
	int v[Maxn], len;
	
	BigInteger(int num = 0) { *this = num; }
	BigInteger(const string &str) { *this = str; }

	BigInteger operator = (int num)
	{
		len = 0;
		memset(v, 0, sizeof v);
		do
		{
			v[++len] = num % 10;
			num /= 10;
		} while(num);
		return *this;
	}
	BigInteger operator = (const string &str)
	{
		len = 0;
		memset(v, 0, sizeof v);
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

} f[Maxk][Maxn], v[Maxn][Maxn]; 
// f[k][pos] maxv of put k'th * to pos'back
// v[l][r] value of [l, r]

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
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; ++j)
		{
			v[i][j] = num.substr(i-1, (j-i+1));
#ifdef DEBUG
//			cout << i << " " << j << " " << v[i][j] << endl;
#endif
		}
	for(int i = 1; i <= n; ++i)
		f[0][i] = v[1][i];
	f[0][0] = 1;
	// dp
	for(int i = 1; i <= k; ++i)
		for(int p = i; p < n; ++p)
			for(int j = i-1; j < p; ++j)
			{
				f[i][p] = max(f[i][p], f[i-1][j] * v[j+1][p]);
#ifdef DEBUG
				cout << i << " " << p << " " << f[i][p] << endl;
#endif
			}

	BigInteger ans = 0;
	for(int i = k; i < n; ++i)
		ans = max(ans, f[k][i] * v[i+1][n]);
	cout << ans << endl;
	return 0;
}
