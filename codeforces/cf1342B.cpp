/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 22:34:31
 * @LastEditTime: 2020-04-26 22:54:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

string t, s;
int cnt[2];

inline bool check() {
    int n = t.size();
    for (int i = 0; i < n; i += 2) {
        if (t[i] != t[0]) return false;
    }
    for (int i = 1; i < n; i += 2) {
        if (t[i] != t[1]) return false;
    }
    return true;
}

inline void solve()
{
    cin >> t;
    if (check()) return void(cout << t << endl);
    s = "";
    for (int i = 0; i < (int)t.size(); ++i) s += "01";
    cout << s << endl;
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