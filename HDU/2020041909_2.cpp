/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 13:41:34
 * @LastEditTime: 2020-04-19 13:43:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

string s;

inline void solve()
{
    cin >> s;
    if (s.size() > 20) return void(cout << "Zhang San will never have girlfriend!" << endl);
    int n = s.size()-1;
    ++s[n];
    while (n && s[n] > '9') {
        s[n] = '0';
        ++s[--n];
    }
    if (s[0] > '9') {
        s[0] = '0';
        s = "1"+s;
    }
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