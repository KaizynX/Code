#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e3+7;

int T, n, h, r;
long long D;
int fa[Maxn];
struct Circle
{
	int x, y, z;
	bool operator < (const Circle &b) const
	{
		return z < b.z;
	}
} a[Maxn];

int getf(int);
inline void co(int, int);
inline void init();
inline bool dis(int, int);
template <typename T> inline void read(T &);

int main()
{
	read(T);
	while(T--)
	{
		read(n); read(h); read(r);
		D = (long long)r*r*4;
		for(int i = 1; i <= n; ++i)
		{
			read(a[i].x);
			read(a[i].y);
			read(a[i].z);
		}
		sort(a+1, a+n+1);
		// special judge
		if(a[1].z > r || h-a[n].z > r)
		{
			puts("No");
			continue;
		}
		init();
		for(int i = 1; i <= n; ++i)
		{
			if(a[i].z <= r) co(0, i);     // bottom
			if(h-a[i].z <= r) co(i, n+1); // top
			for(int j = i+1; j <= n; ++j)
			{
				if(a[j].z - a[i].z > r*2) break;
				if(dis(i, j)) co(i, j);
			}
			if(getf(0) == getf(n+1)) break;
		}
		puts(getf(0) == getf(n+1) ? "Yes" : "No");
	}
}

inline bool dis(int i, int j)
{
	long long d = (long long)(a[i].x-a[j].x)*(a[i].x-a[j].x)
				 +(long long)(a[i].y-a[j].y)*(a[i].y-a[j].y)
				 +(long long)(a[i].z-a[j].z)*(a[i].z-a[j].z);
	return d <= D;
}

inline void co(int i, int j)
{
	int fi = getf(i), fj = getf(j);
	if(fi != fj) fa[fi] = fj;
}

int getf(int s)
{
	return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

inline void init()
{
	for(int i = 0; i <= n+1; ++i) fa[i] = i;
}

template <typename T> inline void read(T &x)
{
	char c; T tag = 1;
	while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
	x = c - '0';
	while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
	x *= tag;
}
