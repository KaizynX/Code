/*
 * @Author: Kaizyn
 * @Date: 2020-04-15 22:27:23
 * @LastEditTime: 2020-04-15 23:37:50
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n[4], p[4];
int a[4][N];

inline long long calc(const long long &x, const long long &y, const long long &z) {
    return (x-y)*(x-y)+(x-z)*(x-z)+(y-z)*(y-z);
}

inline void solve()
{
    for (int i = 0; i < 3; ++i) cin >> n[i], p[i] = i;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n[i]; ++j) {
            cin >> a[i][j];
        }
        sort(a[i], a[i]+n[i]);
        n[i] = unique(a[i], a[i]+n[i])-a[i];
    }
    long long res = 3e18;
    do {
        for (int i = 0, j, k; i < n[p[0]]; ++i) {
            j = upper_bound(a[p[1]], a[p[1]]+n[p[1]], a[p[0]][i])-a[p[1]]-1;
            if (j < 0) continue;
            k = lower_bound(a[p[2]], a[p[2]]+n[p[2]], a[p[0]][i])-a[p[2]];
            if (k >= n[p[2]]) break;
            res = min(res, calc(a[p[0]][i], a[p[1]][j], a[p[2]][k]));
        }
    } while (next_permutation(p, p+3));
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