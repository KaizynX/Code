/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 18:23:00
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 18:29:08
 * @FilePath: \Code\codeforces\cf1323C.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, nl, nr;
string s;

inline void solve()
{
    cin >> n >> s;
    for (char c : s) {
        if (c == '(') ++nl;
        else ++nr;
    }
    if (nl != nr) { cout << -1 << endl; return; }
    int res = 0;
    for (int i = 0, now = 0, cnt = 0, flag = 0; i < (int)s.size(); ++i) {
        now += (s[i] == '(' ? 1 : -1);
        ++cnt;
        if (now == 0) {
            if (flag) res += cnt;
            cnt = flag = 0;
        }
        if (now < 0) flag = 1;
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