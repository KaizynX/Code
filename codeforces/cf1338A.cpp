/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 22:02:10
 * @LastEditTime: 2020-04-12 22:30:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int mv = a[1], dis = 0, k = 0;
    for (int i = 2; i <= n; ++i) {
        dis = max(dis, mv-a[i]);
        mv = max(mv , a[i]);
    }
    long long now = 0;
    while (dis > now) now += (1ll<<k), ++k;
    cout << k << endl;
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