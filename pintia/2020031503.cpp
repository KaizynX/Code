/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 13:38:26
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 14:03:10
 * @FilePath: \Code\pintia\2020031503.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct Node
{
    int x, r;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.r;
    }
} a[N];

int n;

inline bool check()
{
    for (int i = 1, r = a[1].x; i <= n; ++i) {
        if (r < a[i].x) return false;
        r = max(r, a[i].x+a[i].r);
    }
    for (int i = n, l = a[n].x; i; --i) {
        if (l > a[i].x) return false;
        l = min(l, a[i].x-a[i].r);
    }
    return true;
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    if (!check()) { cout << -1 << endl; return; }
    else cout << 3ll*(a[n].x-a[1].x) << endl;
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