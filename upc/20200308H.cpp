/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 21:11:26
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 22:01:13
 * @FilePath: \Code\upc\20200308H.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;
int a[N], b[N];

inline void solve()
{
    cin >> n >> k;
    a[0] = b[0] = 1;
    int i = 0, j = 0;
    while (a[i] < n) {
        ++i;
        a[i] = b[i-1]+1;
        while (a[j+1]*k < a[i]) ++j;
        if (a[j]*k < a[i]) b[i] = b[j]+a[i];
        else b[i] = a[i];
    }
    if (a[i] == n) { cout << "qiqi lose" << endl; return; }
    int res;
    while (n) {
        if (n >= a[i]) {
            n -= a[i];
            res = a[i];
        }
        --i;
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