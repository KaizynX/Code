#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e5 + 7;
const int Maxm = 1e6 + 7;

int n, m;
int st[Maxn][20];
int log_2[Maxn];
// f[k][i] max[k, k+2^i-1]

inline void read(int &);

int main()
{
	read(n); read(m);
	for(int i = 1; i <= n; ++i) read(st[i][0]);
	// init log_2
	for(int i = 2; i <= n; ++i) log_2[i] = log_2[i>>1] + 1;
	// init ST
	for(int j = 1; j <= log_2[n]; ++j)
		for(int i = 1; 1<<j <= n-i+1; ++i) // i + 1<<j - 1 <= n
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	
	int l, r;
	while(m--)
	{
		read(l); read(r);
		// query
		int k = log_2[r-l+1];
		printf("%d\n", max(st[l][k], st[r-(1<<k)+1][k]));
	}
	return 0;
}

inline void read(int &res)
{
	char c;
	while((c=getchar()) < '0' || c > '9');
	res = c - '0';
	while((c=getchar()) >= '0' && c <= '9') res = (res<<1)+(res<<3) + c-'0';
}
