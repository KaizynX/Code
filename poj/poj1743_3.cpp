/*
 * @Author: Kaizyn
 * @Date: 2020-05-04 10:36:46
 * @LastEditTime: 2020-05-04 11:55:56
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

// #define DEBUG

using namespace std;

const int N = 2e4+7;

int n;
int a[N], b[N];
int sa[N], rk[N<<1], height[N];

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
    static int oldrk[N<<1], id[N], px[N], cnt[N], m;
    memset(cnt, 0, sizeof(int) * (m = 256));
    for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[rk[i]]--] = i;
    for (int w = 1, p, i; w <= n; w <<= 1, m = p) {
        for (p = 0, i = n; i > n - w; --i) id[++p] = i;
        for (int i = 1; i <= n; ++i)
            if (sa[i] > w)
                id[++p] = sa[i] - w;
        memset(cnt + 1, 0, sizeof(int) * m);
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

inline bool check(const int &len) {
    if (!len) return true;
    int minp = n+1, maxp = 0;
    for (int i = 2; i <= n; ++i) {
        if (height[i] >= len) {
            minp = min(minp, min(sa[i-1], sa[i]));
            maxp = max(maxp, max(sa[i-1], sa[i]));
            if (maxp-minp > len) return true;
        } else {
            minp = n+1;
            maxp = 0;
        }
    }
    return false;
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        --n;
        for (int i = 1; i <= n; ++i) b[i] = a[i+1]-a[i]+88;
        SA(b, n);
        int l = 0, r = n/2;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        printf("%d\n", l < 4 ? 0 : l+1);
    }
}