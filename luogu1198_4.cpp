// ST
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 2e5 + 7;

int M, D, cnt;
long long t;
int f[Maxn][20], lg2[Maxn];

template <typename T> inline void read(T &);
inline void init_log();
inline void update(int, int);
inline int query(int, int);

int main()
{
	char op; long long tmp;
	read(M); read(D);
	init_log();
	while(M--)
	{
		cin >> op; read(tmp);
		if(op == 'A') update(++cnt, (t + tmp) % D);
		else printf("%d\n", t = query(tmp, cnt));
	}
}

inline void update(int u, int v)
{
	f[u][0] = v;
	for(int i = 1; (1<<i) <= u; ++i)
		f[u][i] = max(f[u][i-1], f[u-(1<<(i-1))][i-1]);
}

inline int query(int len, int r)
{
	return max(f[r][lg2[len]], f[r-len+(1<<lg2[len])][lg2[len]]);
}

inline void init_log()
{
	for(int i = 2; i <= M; ++i) lg2[i] = lg2[i>>1] + 1;
}

template <typename T> inline void read(T &res)
{
	char c; int tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
	res *= tag;
}
