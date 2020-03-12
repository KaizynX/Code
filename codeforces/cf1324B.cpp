/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 21:51:22
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 21:55:47
 * @FilePath: \Code\codeforces\cf1324B.cpp
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
int a[N];

inline bool solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (n < 3) return false;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        if (mp.count(a[i])) {
            if (mp[a[i]] < i-1) return true;
        } else {
            mp[a[i]] = i;
        }
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}