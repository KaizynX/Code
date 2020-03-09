/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 22:39:19
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-04 22:47:22
 * @FilePath: \Code\codeforces\cf1316B.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
string s;

inline void solve()
{
    cin >> n >> s;
    string ss = s;
    int kk = 1;
    for (int k = 2; k <= n; ++k) {
        string pre = s.substr(0, k-1), bac = s.substr(k-1);
        if (bac.size()&1) reverse(pre.begin(), pre.end());
        bac += pre;
        if (bac < ss) {
            ss = bac;
            kk = k;
        }
    }
    cout << ss << endl << kk << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}