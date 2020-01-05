#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int M = 6e5+7;
const int INF = 0x3f3f3f3f;

int L, s, t, n, m;
int a[N], b[N], f[M], dp[M];

int main()
{
    cin >> L >> s >> t >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    m = 1;
    for (int i = s; i <= t; ++i) {
        m *= i/__gcd(m, i);
    }
    for (int i = 1; i <= n; ++i) {
        b[i] = b[i-1]+(a[i]-a[i-1])%m;
        if (a[i]-a[i-1] >= m) b[i] += m;
        // if (b[i] == b[i-1]) b[i] += m;
        f[b[i]] = 1;
    }
#ifdef DEBUG
    for (int i = 1; i <= n; ++i)
        cout << b[i] << " \n"[i==n];
#endif
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= b[n]+2*t; ++i) {
        for (int j = s; j <= t; ++j) {
            if (i >= j) {
                dp[i] = min(dp[i], dp[i-j]+f[i]);
            }
        }
    }
    int res = INF;
    for (int i = b[n]+1; i <= b[n]+2*t; ++i)
        res = min(res, dp[i]);
    cout << res << endl;
    return 0;
}
