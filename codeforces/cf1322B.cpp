/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 11:42:18
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 12:52:13
 * @FilePath: \Code\codeforces\cf1322B.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int res = 0;
    for (int k = 25, base, cnt; k >= 0; --k) {
        base = (1<<(k+1))-1;
        for (int i = 1; i <= n; ++i) a[i] &= base;
        cnt = 0;
        sort(a+1, a+n+1);
        for (int i = 2, l, r; i <= n; ++i) {
            // [2^k, 2^(k+1)) [2^(k+1)+2^k, )
            l = lower_bound(a+1, a+i, (1<<k)-a[i])-a;
            r = lower_bound(a+1, a+i, (1<<(k+1))-a[i])-a;
            cnt = (cnt+(r-l))&1;
            l = lower_bound(a+1, a+i, (1<<(k+1))+(1<<k)-a[i])-a;
            r = i;
            cnt = (cnt+(r-l))&1;
        }
        if (cnt) res |= (1<<k);
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}