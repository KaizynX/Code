/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 19:58:48
 * @LastEditTime: 2020-03-22 20:14:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], t[N];

inline void solve()
{
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++t[a[i]];
    }
    for (int i = 1; i <= n; ++i) {
        res += t[i]*(t[i]-1ll)/2;
    }
    for (int i = 1; i <= n; ++i) {
        if (t[a[i]] <= 1) {
            cout << res << endl;
        } else {
            cout << res-t[a[i]]*(t[a[i]]-1ll)/2+(t[a[i]]-1ll)*(t[a[i]]-2ll)/2 << endl;
        }
    }
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