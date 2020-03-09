/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 21:01:44
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-04 22:37:35
 * @FilePath: \Code\codeforces\cf1316A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
int a[N];

inline void solve()
{
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    cout << min(m, sum) << endl;
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