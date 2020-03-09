/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 17:33:18
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 17:29:14
 * @FilePath: \Code\HDU\hdu4542.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const long long INF = 1ll<<62;

struct Euler
{
    int tot = 0;
    int prime[N];
    bool check[N];
    bool& operator [] (const int i) { return check[i]; }
    void init(int sz) {
        tot = 0;
        for (int i = 1; i <= sz; ++i) check[i] = true;
        check[1] = false;
        for (register int i = 2, j; i <= sz; ++i) {
            if (check[i]) prime[++tot] = i;
            for (j = 1; j <= tot && i*prime[j] <= sz; ++j) {
                check[i*prime[j]] = false;
                if (i%prime[j] == 0) break;
            }
        }
    }
} E;

int t, k;
long long ans;
int a[N];

inline int count_fac(int x)
{
    int res = 1;
    for (int i = 1, k; i <= E.tot && x > 1; ++i) {
        if (x%E.prime[i]) continue;
        k = 0;
        while (x%E.prime[i] == 0) x /= E.prime[i], ++k;
        res *= (k+1);
    }
    return res;
}

inline int search()
{
    for (int i = 2; i*i <= 4*(i+k); ++i)
        if (i == count_fac(i+k)) return i+k;
    return -1;
}

void dfs(int u, int rest, long long now)
{
    if (rest == 1) {
        ans = min(ans, now);
        return;
    }
    long long nex = now;
    for (int i = 1; i <= a[u-1]; ++i) {
        if (INF/E.prime[u] < nex) break;
        nex *= E.prime[u];
        if (nex > INF) break;
        if (rest%(i+1)) continue;
        if (rest < i+1) break;
        a[u] = i;
        dfs(u+1, rest/(i+1), nex);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    E.init(1e5);
    a[0] = 62;
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        scanf("%d %d", &t, &k);
        printf("Case %d: ", i);
        if (t) {
            int res = search();
            if (res == -1) puts("Illegal");
            else printf("%d\n", res);
        } else {
            ans = INF+1;
            dfs(1, k, 1);
            if (ans > INF) puts("INF");
            else printf("%lld\n", ans);
        }
    }
    return 0;
}