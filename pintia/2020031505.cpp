/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 14:04:06
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 14:47:23
 * @FilePath: \Code\pintia\2020031505.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;
int x[N], y[N];
int res[N];
vector<int> v;

inline void solve()
{
    cin >> n >> k;
    int lx = INF, ly = INF, rx = 0, ry = 0;
    memset(res, 0x3f, sizeof res);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
        lx = min(lx, x[i]);
        ly = min(ly, y[i]);
        rx = max(rx, x[i]);
        ry = max(ry, y[i]);
    }
    for (int i = lx; i <= rx; ++i) {
        for (int j = ly; j <= ry; ++j) {
            v.clear();
            for (int l = 1; l <= n; ++l) {
                v.emplace_back(abs(i-x[l])+abs(j-y[l]));
            }
            sort(v.begin(), v.end());
            for (int l = 0, sum = 0; l < k; ++l) {
                sum += v[l];
                res[l+1] = min(res[l+1], sum);
            }
        }
    }
    for (int i = 1; i <= k; ++i) {
        cout << res[i] << endl;
    }
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