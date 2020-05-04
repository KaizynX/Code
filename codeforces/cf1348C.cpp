/*
 * @Author: Kaizyn
 * @Date: 2020-05-01 22:32:15
 * @LastEditTime: 2020-05-01 23:01:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;
string s;

inline void solve()
{
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    if (s[k-1] == s[0]) {
        if(s[k] == s.back()) {
            int cnt = s.size()-k;
            cout << s[0] << string((cnt+k-1)/k, s[k]) << endl;
        } else {
            cout << s.substr(k-1) << endl;
        }
    } else {
        cout << s[k-1] << endl;
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