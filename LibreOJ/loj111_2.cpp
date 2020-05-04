/*
 * @Author: Kaizyn
 * @Date: 2020-05-01 18:37:13
 * @LastEditTime: 2020-05-03 23:36:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

char s[N];
int sa[N], rk[N<<1], height[N];

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
    static int oldrk[N<<1], id[N], px[N], cnt[N], m;
    m = 128;
    for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[rk[i]]--] = i;
    for (int w = 1, p, i; w <= n; w <<= 1, m = p) {
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > w)
                id[++p] = sa[i] - w;
        memset(cnt, 0, sizeof(int) * (m + 1));
        for (int i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
        for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n; i; --i) sa[cnt[px[i]]--] = id[i];
        memcpy(oldrk + 1, rk + 1, sizeof(int) * n);
        for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    for (int i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]] = k;
    }
#undef cmp
}
signed main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    SA(s, n);
    for (int i = 1; i <= n; ++i) printf("%d%c", sa[i], " \n"[i==n]);
    for (int i = 1; i <= n; ++i) printf("%d%c", height[i], " \n"[i==n]);
    return 0;
}