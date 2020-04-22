/*
 * @Author: Kaizyn
 * @Date: 2020-04-21 19:56:23
 * @LastEditTime: 2020-04-21 20:45:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int K = 5;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m, k;
int xmw[N][K], xsw[N][K];
long long vmw[N][1<<K], vsw[N][1<<K];
long long mmw[1<<K], msw[1<<K];

inline void solve()
{
    memset(mmw, 0x8f, sizeof mmw);
    memset(msw, 0x8f, sizeof msw);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1, s; i <= n; ++i) {
        scanf("%d", &s);
        for (int j = 0; j < k; ++j) scanf("%d", &xmw[i][j]);
        for (int j = 0; j < 1<<k; ++j) {
            vmw[i][j] = s;
            for (int l = 0; l < k; ++l)
                vmw[i][j] += ((j>>l)&1 ? 1 : -1)*xmw[i][l];
            mmw[j] = max(mmw[j], vmw[i][j]);
        }
    }
    for (int i = 1, s; i <= m; ++i) {
        scanf("%d", &s);
        for (int j = 0; j < k; ++j) scanf("%d", &xsw[i][j]);
        for (int j = 0; j < 1<<k; ++j) {
            vsw[i][j] = s;
            for (int l = 0; l < k; ++l)
                vsw[i][j] += ((j>>l)&1 ? 1 : -1)*xsw[i][l];
            msw[j] = max(msw[j], vsw[i][j]);
        }
    }
    long long res = -INF;
    for (int i = 0, j, base = (1<<k)-1; i < 1<<k; ++i) {
        j = base^i;
        res = max(res, mmw[i]+msw[j]);
    }
    printf("%lld\n", res);
}

signed main()
{
    int testcase = 1;
    scanf("%d", &testcase);
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}