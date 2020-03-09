/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 20:53:28
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 21:00:56
 * @FilePath: \Code\atcoder\abc158D.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

string s, pre, bac;
int q, rev;

inline void solve()
{
    int t, f;
    char c;
    cin >> s >> q;
    while (q--) {
        cin >> t;
        if (t == 1) rev ^= 1;
        else {
            cin >> f >> c;
            if (f == 1 && rev) {
                bac += c;
            } else if (f == 1 && !rev) {
                pre += c;
            } else if (f == 2 && rev) {
                pre += c;
            } else {
                bac += c;
            }
        }
    }
    if (!rev) {
        reverse(pre.begin(), pre.end());
        cout << pre << s << bac << endl;
    } else {
        reverse(bac.begin(), bac.end());
        reverse(s.begin(), s.end());
        cout << bac << s << pre << endl;
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