#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define DEBUG

using namespace std;

const char c[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int N;

struct Node
{
	string v;

	Node(){}
	Node(string &str) { *this = str; }

	Node operator = (const string &str) 
	{
		v = str;
		reverse(v.begin(), v.end());
		return *this; 
	}

	Node operator + (const Node &b) const
	{
		Node res;
		for(unsigned i = 0, g = 0; i < v.length() || i < b.v.length() || g; ++i)
		{
			if(i < v.length()) g += getv(v[i]);
			if(i < b.v.length()) g += getv(b.v[i]);
			res.v.push_back(c[g%N]);
			g /= N;
		}
		// reverse(res.v.begin(), res.v.end());
		return res;
	}

	inline int getv(char c) const
	{
		if(c >= '0' && c <= '9') return c - '0';
		else return 10 + c - 'A';
	}

	inline Node _reverse() const
	{
		Node res = *this;
		reverse(res.v.begin(), res.v.end());
		return res;
	}

	inline bool is_huiwen() const
	{
		for(unsigned b = 0, e = v.length()-1; b < e; ++b, --e)
			if(v[b] != v[e]) return false;
		return true;
	}

} M;

istream& operator >> (istream &is, Node &a)
{
	is >> a.v;
	return is;
}

ostream& operator << (ostream &os, Node &a)
{
	Node res = a;
	reverse(res.v.begin(), res.v.end());
	os << res.v;
	return os;
}

int main()
{
	cin >> N >> M;
	if(M.is_huiwen())
	{
		puts("STEP=0");
		return 0;
	}
	for(int i = 1; i <= 30; ++i)
	{
#ifdef DEBUG
		Node tmp = M._reverse();
		cout << i << " " << M << " + " << tmp << " = ";
#endif
		M = M + M._reverse();
#ifdef DEBUG
		cout << M << endl;
#endif
		if(M.is_huiwen())
		{
			printf("STEP=%d\n", i);
			return 0;
		}
	}
	puts("Impossible!");
	return 0;
}
