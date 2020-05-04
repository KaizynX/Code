/*
 * @Author: Kaizyn
 * @Date: 2020-05-04 10:36:46
 * @LastEditTime: 2020-05-04 19:02:45
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define DEBUG

using namespace std;

const int N = 2e4+7;

struct ST_MIN
{
    int lg2[N];
    int rmq[N][20]; // rmq[i][j] ==> [i-2^j+1, i]
    ST_MIN() {
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    }
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

int n, k;
int a[N];
int sa[N], rk[N<<1], height[N];
ST_MIN st;

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

int main() {
    while (scanf("%d %d", &n, &k) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        SA(a, n);
        st.build(height, n);
        int res = 0;
        for (int i = 1; i+k-2 <= n; ++i) {
            res = max(res, st.query(i, i+k-2));
        }
        printf("%d\n", res);
        #ifdef DEBUG
        for (int i = 1; i <= n; ++i) printf("%d%c", height[i], " \n"[i==n]);
        #endif
    }
}