/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 21:59:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 22:08:31
 * @FilePath: \Code\codeforces\cf1324C.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

vector<int> p;
string s;

inline void solve()
{
    cin >> s;
    int n = s.size();
    vector<int>(1, 0).swap(p);
    for (int i = 1; i <= n; ++i) {
        if (s[i-1] == 'R') p.emplace_back(i);
    }
    p.emplace_back(n+1);
    int res = 0;
    for (int i = 1; i < (int)p.size(); ++i) {
        res = max(res, p[i]-p[i-1]);
    }
    cout << res << endl;
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