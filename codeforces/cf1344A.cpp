/*
 * @Author: Kaizyn
 * @Date: 2020-05-06 22:33:08
 * @LastEditTime: 2020-05-06 22:48:52
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

int n;
int a[N], vis[N];

inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) vis[i] = 0;
    for (int i = 0; i < n; ++i) {
        a[i] = (a[i]%n+n)%n;
        int nex = (i+a[i])%n;
        if (vis[nex]) return void(cout << "NO" << endl);
        vis[nex] = 1;
    }
    cout << "YES" << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}