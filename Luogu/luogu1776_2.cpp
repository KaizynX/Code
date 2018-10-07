#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;
const int Maxm = 4e4+7;

int n, W;
int f[Maxm];
int q[Maxm], head, tail;
int v[Maxn], w[Maxn], m[Maxn];

// f[i][u+p*wi] = max{ f[i-1][u+k*wi]+(p-k)*vi } (p-mi <= k < p)
// f[i][u+p*wi] = p*vi + max{ f[i-1][u+k*wi]-k*vi }

inline int calc(int u, int i, int k)
{
	return f[u+k*w[i]]-k*v[i];
}

int main()
{
	scanf("%d%d", &n, &W);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", v+i, w+i, m+i);
		for(int u = 0; u < w[i]; ++u)
		{
			int maxp = (W-u)/w[i];
			head = 1; tail = 0;
			for(int k = maxp-1; k >= max(0, maxp-m[i]); --k)
			{
				while(head <= tail && calc(u, i, q[tail]) <= calc(u, i, k)) tail--;
				q[++tail] = k;
			}
			for(int p = maxp; p >= 0; --p)
			{
				while(head <= tail && q[head] >= p) head++;
				f[u+p*w[i]] = max(f[u+p*w[i]], p*v[i]+calc(u, i, q[head]));
				if(p-m[i]-1 < 0) continue;
				while(head <= tail && calc(u, i, q[tail]) <= calc(u, i, p-m[i]-1)) tail--;
				q[++tail] = p-m[i]-1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= W; ++i)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
