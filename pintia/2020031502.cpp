/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 13:32:12
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 13:37:48
 * @FilePath: \Code\pintia\2020031502.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
string s;
double h, m, hh, mm;

inline void solve()
{
    cin >> n >> s;
    h = m = 0.5;
    hh = mm = 0.5;
    for (char c : s) {
        h /= 2; m /= 2;
        if (c == 'H') {
            hh += 0.5;
            h += 0.5;
        } else if (c == 'M') {
            mm += 0.5;
            m += 0.5;
        }
    }
    hh -= h; mm -= m;
    if (hh == mm) cout << "HM" << endl;
    else if (hh > mm) cout << "H" << endl;
    else if (hh < mm) cout << "M" << endl;
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