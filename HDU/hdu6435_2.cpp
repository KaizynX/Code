/*
 * @Author: Kaizyn
 * @Date: 2020-04-21 19:56:23
 * @LastEditTime: 2020-04-21 21:05:39
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
int xmw[K], xsw[K];
long long vmw[1<<K], vsw[1<<K], mmw[1<<K], msw[1<<K];
int lg2[1<<K];

inline int lowbit(const int &x) { return x&-x; }

inline void solve()
{
    memset(mmw, 0x8f, sizeof mmw);
    memset(msw, 0x8f, sizeof msw);

    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1, s; i <= n; ++i) {
        scanf("%d", &s);
        vmw[0] = s;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &xmw[j]);
            vmw[0] -= xmw[j];
        }
        mmw[0] = max(mmw[0], vmw[0]);
        for (int j = 1, l; j < 1<<k; ++j) {
            l = lowbit(j);
            vmw[j] = vmw[j^l]+2*xmw[lg2[l]];
            mmw[j] = max(mmw[j], vmw[j]);
        }
    }
    for (int i = 1, s; i <= m; ++i) {
        scanf("%d", &s);
        vsw[0] = s;
        for (int j = 0; j < k; ++j) {
            scanf("%d", &xsw[j]);
            vsw[0] -= xsw[j];
        }
        msw[0] = max(msw[0], vsw[0]);
        for (int j = 1, l; j < 1<<k; ++j) {
            l = lowbit(j);
            vsw[j] = vsw[j^l]+2*xsw[lg2[l]];
            msw[j] = max(msw[j], vsw[j]);
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
    for (int i = 0; i < K; ++i) lg2[1<<i] = i;
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}