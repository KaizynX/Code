#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
const int M = 1e5+7;

int n, m;
long long dp[M];

struct Node
{
    int a, b, c;
    friend bool operator < (const Node &n1, const Node &n2) {
        return 1ll*n2.b*n1.c < 1ll*n1.b*n2.c;
    }
} a[N];

int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].a;
    for (int i = 1; i <= n; ++i) cin >> a[i].b;
    for (int i = 1; i <= n; ++i) cin >> a[i].c;
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = m; j >= a[i].c; --j)
            dp[j] = max(dp[j], dp[j-a[i].c]+a[i].a-1ll*a[i].b*j);
    }
    long long res = 0;
    for (int i = 0; i <= m; ++i)
        res = max(res, dp[i]);
    cout << res << endl;
    return 0;
}
