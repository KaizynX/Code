#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m;
int a[N], b[N], fa[N], num[N];
long long res[N];

int getf(int s) { return fa[s] == s ? s : fa[s] = getf(fa[s]); }

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", a+i, b+i);
    }
    for (int i = 1; i <= n; ++i) {
        fa[i] = i;
        num[i] = 1;
    }
    res[m] = 1ll*n*(n-1)/2;
    for (int i = m; i; --i) {
        int fx = getf(a[i]), fy = getf(b[i]);
        long long dec = 0;
        if (fx != fy) {
            dec = 1ll*num[fx]*num[fy];
            fa[fx] = fy;
            num[fy] += num[fx];
        }
        res[i-1] = res[i]-dec;
    }
    for (int i = 1; i <= m; ++i) {
        printf("%lld\n", res[i]);
    }
    return 0;
}
