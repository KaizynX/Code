/*
 * @Author: Kaizyn
 * @Date: 2020-03-27 23:01:13
 * @LastEditTime: 2020-03-27 23:42:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], t[N], s[N];

inline void solve()
{
    memset(t, 0, sizeof t);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++t[a[i]];
    }
    for (int i = 1; i <= 100000; ++i) s[i] = s[i-1]+t[i];
    sort(a+1, a+n+1);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        // regard a[i] as the longest edge
        // b+c > a[i]
        // for (j : [1, a[i]/2]) res += t[j]*(s[a[i]]-s[a[i]-j])
        // regard a[i] as the shortest edge
        // b-c > a[i]
        // for (j >= a[i]) res += (s[a[i]+j-1]-s[j-1])
    }
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