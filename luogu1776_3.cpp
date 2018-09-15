#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;
const int Maxm = 4e4+7;

int n, W, v, w, m;
int f[Maxm], q[Maxm], head, tail;

// f[i][u+p*wi] = max{ f[i-1][u+k*wi]+(p-k)*vi } (p-mi <= k < p)
// f[i][u+p*wi] = p*vi + max{ f[i-1][u+k*wi]-k*vi }

inline int calc(int u, int k)
{
	return f[u+k*w]-k*v;
}

int main()
{
	scanf("%d%d", &n, &W);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d", &v, &w, &m);
		for(int u = 0; u < w; ++u)
		{
			int maxp = (W-u)/w;
			head = 1; tail = 0;
			for(int k = maxp-1; k >= max(0, maxp-m); --k)
			{
				while(head <= tail && calc(u, q[tail]) <= calc(u, k)) tail--;
				q[++tail] = k;
			}
			for(int p = maxp; p >= 0; --p)
			{
				while(head <= tail && q[head] >= p) head++;
				if(head <= tail) f[u+p*w] = max(f[u+p*w], p*v+calc(u, q[head]));
				if(p-m-1 < 0) continue;
				while(head <= tail && calc(u, q[tail]) <= calc(u, p-m-1)) tail--;
				q[++tail] = p-m-1;
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= W; ++i)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}
