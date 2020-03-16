/*
 * @Author: Kaizyn
 * @Date: 2020-03-16 17:27:28
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 17:30:31
 * @FilePath: \Code\atcoder\panasonic2020D.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 10;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
string s;

void f(const int &u, const int &l)
{
    if (u >= n) {
        cout << s << endl;
        return;
    }
    for (int i = 0; i <= l+1; ++i) {
        s.push_back('a'+i);
        f(u+1, max(l, i));
        s.pop_back();
    }
}

inline void solve()
{
    cin >> n;
    f(0, -1);
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