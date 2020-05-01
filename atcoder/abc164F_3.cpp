/*
 * @Author: Kaizyn
 * @Date: 2020-04-28 23:37:37
 * @LastEditTime: 2020-04-29 17:12:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int s[N], t[N], u[N], v[N], a[N][N], r[N][2], c[N][2];
unsigned long long uu[N], vv[N];
unsigned long long res[N][N];

inline bool solve()
{
    for (int b = 0; b < 64; ++b) {
        memset(a, -1, sizeof a);
        memset(r, 0, sizeof r);
        memset(c, 0, sizeof c);
        for (int i = 1; i <= n; ++i) {
            u[i] = (uu[i]>>b)&1;
            v[i] = (vv[i]>>b)&1;
        }
        for (int i = 1; i <= n; ++i) {
            if (s[i] == u[i]) continue;
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] != -1 && a[i][j] != u[i]) return false;
                else a[i][j] = u[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (t[i] == v[i]) continue;
            for (int j = 1; j <= n; ++j) {
                if (a[j][i] != -1 && a[j][i] != v[i]) return false;
                else a[j][i] = v[i];
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (u[i] == v[j]) a[i][j] = u[i];
                if (a[i][j] == -1) a[i][j] = 0;
                ++r[i][a[i][j]];
                ++c[j][a[i][j]];
            }
        }
        for (int i = 1; i <= n; ++i) if (s[i] && u[i] && !r[i][1]) {
            for (int j = 1; j <= n; ++j) if (!t[j] && !v[j] && c[j][0] > 1) {
                a[i][j] = 1;
                --c[j][0]; ++c[j][1];
                --r[i][0]; ++r[i][1];
                break;
            }
        }
        for (int i = 1; i <= n; ++i) if (t[i] && v[i] && !c[i][1]) {
            for (int j = 1; j <= n; ++j) if (!s[j] && !u[j] && r[j][0] > 1) {
                a[j][i] = 1;
                --c[i][0]; ++c[i][1];
                --r[j][0]; ++r[j][1];
                break;
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (s[i] && u[i] && !r[i][1]) return false;
            if (s[i] && !u[i] && r[i][1]) return false;
            if (!s[i] && u[i] && r[i][0]) return false;
            if (!s[i] && !u[i] && !r[i][0]) return false;
            if (t[i] && v[i] && !c[i][1]) return false;
            if (t[i] && !v[i] && c[i][1]) return false;
            if (!t[i] && v[i] && c[i][0]) return false;
            if (!t[i] && !v[i] && !c[i][0]) return false;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j]) res[i][j] += 1ull<<b;
            }
        }
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> uu[i];
    for (int i = 1; i <= n; ++i) cin >> vv[i];
    if (!solve()) cout << -1 << endl;
    else {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << res[i][j] << " \n"[j==n];
            }
        }
    }
    return 0;
}