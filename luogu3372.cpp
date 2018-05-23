#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5 + 7;

int n, m;
long long b[Maxn], bi[Maxn], s[Maxn];

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}

inline void add(long long *arr, int i, long long v)
{
	for( ; i <= n; i += i & -i) arr[i] += v;
}

inline long long ask(long long *arr,int x) // return SUM of arr[1~x]
{
	long long res = 0;
	for( ; x; x -= x & -x) res += arr[x];
	return res;
}

inline long long query(int x, int y)
{
	// (i+1) * sum(b,i) - sum(bi,i)
#ifdef DEBUG
	printf("%lld %lld %lld %lld %lld\n",ask(b, y) , ask(bi, y) , ask(b, x-1) , ask(bi, x-1) , s[y] - s[x-1]);
#endif
	// return (y+1)*ask(b, y) - ask(bi, y) + x*ask(b, x-1) - ask(bi, x-1) + s[y] - s[x-1];
	long long sumy = s[y] + (y+1)*ask(b, y) - ask(bi, y),
		      sumx = s[x-1] + x*ask(b,x-1) - ask(bi, x-1);
	return sumy - sumx;
}

int main()
{
	long long k;
	read(n); read(m);
	for(int i = 1; i <= n; ++i)
	{
		read(k);
		s[i] = s[i-1] + k;
	}
	for(int i = 0, op, x, y; i < m; ++i)
	{
		read(op); read(x); read(y);
		if(op == 1)
		{
			read(k);
			add(b, x, k); add(b, y+1, -k);
			add(bi, x, x*k); add(bi, y+1, -(y+1)*k);
		}
		else printf("%lld\n",query(x,y));
	}
	return 0;
}
