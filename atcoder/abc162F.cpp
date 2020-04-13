/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 19:55:49
 * @LastEditTime: 2020-04-12 20:36:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N];
long long sum;
long long pre[N], suf[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    long long res = 0;
    if (n&1) {
        pre[1] = a[1];
        for (int i = 2; i <= n; ++i) {
            pre[i] = pre[i-2]+a[i];
        }
        for (int i = n; i; --i) {
            suf[i] = suf[i+2]+a[i];
        }
        for (int i = 1; i < n; ++i) {
            if (i&1) res = max(res, pre[i]+suf[i+4]);
            else res = max(res, pre[i]+suf[i+3]);
        }
        for (int i = n; i >= 3; --i) {
            if (i&1) res = max(res, suf[i]+pre[i-4]);
            else res = max(res, suf[i]+pre[i-3]);
        }
    } else {
        long long half = 0;
        for (int i = 1; i <= n; i += 2) half += a[i];
        res = max(half, sum-half);
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