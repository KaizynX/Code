/*
 * @Author: Kaizyn
 * @Date: 2020-05-06 14:14:46
 * @LastEditTime: 2020-05-06 16:37:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m, tot;
int a[N], b[N], lg2[N], nex[N], num[N];
int rmq[N][20];

inline int mv(const int &x, const int &y) {
    if (a[x] == a[y]) return min(x, y);
    return a[x] > a[y] ? x : y;
}

inline void st_init() {
    for (int i = n; i; --i) {
        rmq[i][0] = i;
        for (int j = 1; j <= lg2[n-i+1]; ++j)
            rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
}

inline int get_next(const int &i, const int &val) {
    int j = i;
    for (int b = lg2[n-i]; b >= 0; --b) {
        if (j+(1<<b) <= n && a[rmq[j+1][b]] <= val)
            j += 1<<b;
    }
    assert(j <= n);
    return j+1;
}

inline void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    st_init();
    num[n+1] = 0;
    for (int i = n; i; --i) {
        nex[i] = get_next(i, a[i]);
        num[i] = num[nex[i]]+1;
        assert(nex[i] > i);
    }
    nex[0] = 1;
    // num[0] = num[1];
    tot = 0;
    for (int i = 1; i <= n; i = nex[i]) b[++tot] = i;
    #ifdef DEBUG
    for (int i = 0; i <= n; ++i) printf("%d%c", nex[i], " \n"[i==n]);
    for (int i = 0; i <= n; ++i) printf("%d%c", num[i], " \n"[i==n]);
    #endif
    for (int i = 1, p, q, last; i <= m; ++i) {
        scanf("%d%d", &p, &q);
        last = *(lower_bound(b+1, b+tot+1, p)-1);
        assert(last >= 0);
        if (q > a[last]) {
            printf("%d\n", tot-num[nex[last]]+(num[get_next(p, q)]+1));
        } else {
            printf("%d\n", tot-num[nex[last]]+num[get_next(p, a[last])]);
        }
    }
}

signed main()
{
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}