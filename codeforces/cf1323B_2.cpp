/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 18:03:49
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 18:10:47
 * @FilePath: \Code\codeforces\cf1323B_2.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 4e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, k;
int a[N], b[N], sa[N], sb[N];
long long ca[N], cb[N];

inline void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], sa[i] = a[i] ? sa[i-1]+a[i] : 0;
    for (int i = 1; i <= m; ++i) cin >> b[i], sb[i] = b[i] ? sb[i-1]+b[i] : 0;
    ca[1] = n; cb[1] = m;
    for (int i = 1; i <= n; ++i) --ca[sa[i]+1];
    for (int i = 1; i <= m; ++i) --cb[sb[i]+1];
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << sa[i] << " \n"[i==n];
    for (int i = 1; i <= m; ++i) cout << sb[i] << " \n"[i==m];
    #endif
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << ca[i] << " \n"[i==n];
    for (int i = 1; i <= m; ++i) cout << cb[i] << " \n"[i==m];
    #endif
    for (int i = 1; i <= n; ++i) ca[i] += ca[i-1];
    for (int i = 1; i <= m; ++i) cb[i] += cb[i-1];
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << ca[i] << " \n"[i==n];
    for (int i = 1; i <= m; ++i) cout << cb[i] << " \n"[i==m];
    #endif
    long long res = 0;
    for (int i = 1; i*i <= k; ++i) {
        if (k%i) continue;
        if (i <= n && k/i <= m) res += ca[i]*cb[k/i];
        if (i != k/i && i <= m && k/i <= n) res += ca[k/i]*cb[i];
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