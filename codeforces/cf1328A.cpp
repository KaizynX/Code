/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 22:35:53
 * @LastEditTime: 2020-03-26 22:42:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int a, b;

inline void solve()
{
    cin >> a >> b;
    cout << (b-a%b)%b << endl;
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