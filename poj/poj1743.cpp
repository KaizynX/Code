/*
 * @Author: Kaizyn
 * @Date: 2020-05-04 10:36:46
 * @LastEditTime: 2020-05-04 12:02:23
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

// #define DEBUG

using namespace std;

const int N = 2e4+7;
int lg2[N];

struct ST_MIN
{
    int rmq[N][20]; // rmq[i][j] ==> [i-2^j+1, i]
    void build(int a[], const int &n) {
        for (int i = 1; i <= n; ++i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[i]; ++j)
                rmq[i][j] =  min(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
        }
    }
    int query(const int &l, const int &r) {
        int k = lg2[r-l+1];
        return min(rmq[r][k], rmq[l+(1<<k)-1][k]);
    }
};

struct ST_MAX
{
    int rmq[N][20]; // rmq[i][j] ==> [i-2^j+1, i]
    void build(int a[], const int &n) {
        for (int i = 1; i <= n; ++i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[i]; ++j)
                rmq[i][j] =  max(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
        }
    }
    int query(const int &l, const int &r) {
        int k = lg2[r-l+1];
        return max(rmq[r][k], rmq[l+(1<<k)-1][k]);
    }
};

int n;
int a[N], b[N];
int sa[N], rk[N<<1], height[N];
ST_MIN minp;
ST_MAX maxp;

int w;
inline bool cmp(const int &x, const int &y) {
    return rk[x] == rk[y] ? rk[x+w] < rk[y+w] : rk[x] < rk[y];
}

inline void SA(int *s, const int &n) {
    static int oldrk[N<<1];
    for (int i = 1; i <= n; ++i) rk[i] = s[i];
    for (w = 1; w <= n; w <<= 1) {
        for (int i = 1; i <= n; ++i) sa[i] = i;
        sort(sa+1, sa+n+1, cmp);
        memcpy(oldrk+1, rk+1, sizeof(int)*n);
        for (int p = 0, i = 1; i <= n; ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i-1]] &&
                oldrk[sa[i]+w] == oldrk[sa[i-1]+w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    for (int i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]] = k;
    }
}

inline bool check(const int &len) {
    if (!len) return true;
    int l = 0, r = 1;
    while (1) {
        l = r;
        while (l <= n && height[l] < len) ++l;
        if (l > n) break;
        r = l+1;
        while (r <= n && height[r] >= len) ++r;
        if (maxp.query(l-1, r-1)-minp.query(l-1, r-1) > len) return true;
    }
    return false;
}

#ifdef DEBUG
inline void print(const int &x) {
    for (int i = x; i <= n; ++i) printf("%d%c", b[i], " \n"[i==n]);
}
#endif

int main() {
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        --n;
        for (int i = 1; i <= n; ++i) b[i] = a[i+1]-a[i];
        SA(b, n);
        #ifdef DEBUG
        for (int i = 1; i <= n; ++i) {
            printf("sa[%2d]=%2d ", i, sa[i]);
            print(sa[i]);
        }
        for (int i = 1; i <= n; ++i) printf("%d%c", height[i], " \n"[i==n]);
        #endif
        minp.build(sa, n);
        maxp.build(sa, n);
        int l = 0, r = n/2;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        printf("%d\n", l < 4 ? 0 : l+1);
    }
}