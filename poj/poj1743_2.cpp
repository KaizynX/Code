/*
 * @Author: Kaizyn
 * @Date: 2020-05-04 10:36:46
 * @LastEditTime: 2020-05-04 11:43:23
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
    int l = 0, r = 1, minp, maxp;
    while (1) {
        l = r;
        while (l <= n && height[l] < len) ++l;
        if (l > n) break;
        r = l+1;
        minp = min(sa[l-1], sa[l]);
        maxp = max(sa[l-1], sa[l]);
        while (r <= n && height[r] >= len) {
            minp = min(minp, sa[r]);
            maxp = max(maxp, sa[r]);
            ++r;
        }
        if (maxp-minp > len) return true;
    }
    return false;
}

int main() {
    while (~scanf("%d", &n) && n) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        --n;
        for (int i = 1; i <= n; ++i) b[i] = a[i+1]-a[i];
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