/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 21:08:03
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 21:09:48
 * @FilePath: \Code\atcoder\abc158B.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

long long n, a, b;

inline void solve()
{
    cin >> n >> a >> b;
    long long t = n/(a+b), r = n-t*(a+b);
    cout << t*a+min(a, r) << endl;
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