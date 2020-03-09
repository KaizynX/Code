/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 17:32:46
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 17:37:47
 * @FilePath: \Code\codeforces\cf1323A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    vector<int> odd, even;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]&1) odd.emplace_back(i);
        else even.emplace_back(i);
    }
    if (even.size()) {
        cout << 1 << endl << even.front() << endl;
    } else if (odd.size() > 1) {
        cout << 2 << endl << odd[0] << ' ' << odd[1] << endl;
    } else {
        cout << -1 << endl;
    }
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