#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;
const int INF = 1e9;

int n, k, res;
int x[MAXN], y[MAXN], fa[MAXN<<1], num[MAXN<<1];

int GetF(int x)
{
    return x == fa[x] ? x : fa[x] = GetF(fa[x]);
}

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) fa[i] = i, num[i] = 1;
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", x+i, y+i);
        int fx = GetF(x[i]), fy = GetF(y[i]);
        if (fx != fy) fa[fx] = fy, num[fy] += num[fx];
    }
    for (int i = 1; i <= n*2; ++i) {
        if (fa[i] != i) continue;
        res += num[i]-1;
    }
    printf("%d\n", k-res);
    return 0;
}
