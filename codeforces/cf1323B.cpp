/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 17:38:57
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 17:59:54
 * @FilePath: \Code\codeforces\cf1323B.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, k;
int a[N], b[N], sa[N], sb[N];
long long cnt[N];

inline long long count(const int &r, const int &c)
{
    if (r > n || c > m) return 0;
    long long res = 0;
    for (int i = r; i <= n; ++i) {
        if (sa[i]-sa[i-r] < r) continue;
        res += cnt[c];
    }
    return res;
}

inline void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], sa[i] = sa[i-1]+a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i], sb[i] = sb[i-1]+b[i];
    cnt[0] = m;
    for (int i = 1; i <= m; ++i) --cnt[sb[i]+1];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i-1];
    #ifdef DEBUG
    for (int i = 1; i <= m; ++i) cout << cnt[i] << " \n"[i==m];
    #endif
    long long res = 0;
    for (int i = 1; i*i <= k; ++i) {
        if (k%i) continue;
        res += count(i, k/i);
        if (i != k/i) res += count(k/i, i);
    }
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}