#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const int MOD = 998244353;

int T;
int a[2][Maxn], res[Maxn];

struct Node
{
    int n, id;
    bool operator < (const Node &b) const { return n < b.n; }
} b[Maxn];

inline void solve()
{
    int cur = 1, N = b[T].n;
    a[0][1] = 1;
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= i; ++j)
            a[i&1][j] = ((a[(i+1)&1][j-1]+a[(i+1)&1][j])%MOD+a[i&1][j-1])%MOD;
        while(cur <= T && b[cur].n == i) res[b[cur++].id] = a[i&1][i];
    }
}

int main()
{
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i)
        scanf("%d", &b[i].n), b[i].id = i;
    sort(b+1, b+T+1);
    solve();
    for(int i = 1; i <= T; ++i)
        printf("%d\n", res[i]);
    return 0;
}
