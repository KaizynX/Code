#include <cstdio>
#include <climits>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;
const long long INF = 1e15;

long long W, S, N, sum[Maxn];
double f[Maxn];

struct Car
{
	int w, v;
	double t;
} a[Maxn];

inline double maxt(int l, int r)
{
	double res = 0;
	for(int i = l; i <= r; ++i)
		res = max(res, a[i].t);
	return res;
}

int main()
{
	scanf("%lld%lld%lld", &W, &S, &N);
	S *= 60;
	for(int i = 1; i <= N; ++i)
	{
		scanf("%lld%lld", &a[i].w, &a[i].v);
		sum[i] = sum[i-1]+a[i].w;
		a[i].t = (double)S/a[i].v;
	}
	for(int i = 1; i <= N; ++i)
	{
		f[i] = INF;
		// start a new queue for j
		for(int j = i; j; --j)
		{
			if(sum[i]-sum[j-1] > W) break;
			f[i] = min(f[i], f[j-1]+maxt(j, i));
		}
	}
	printf("%.1f\n", f[N]);
	return 0;
}
