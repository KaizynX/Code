/*
 * @Author: Kaizyn
 * @Date: 2020-04-28 17:22:11
 * @LastEditTime: 2020-04-28 20:11:01
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
int s[N], t[N];
unsigned long long u[N], v[N], uu[N], vv[N];
unsigned long long a[N][N], res[N][N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> uu[i];
    for (int i = 1; i <= n; ++i) cin >> vv[i];

    for (int b = 0; b < 64; ++b) {
        for (int i = 1; i <= n; ++i) {
            u[i] = (uu[i]>>b)&1;
            v[i] = (vv[i]>>b)&1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i] && t[j]) { // | |
                    a[i][j] = u[i]&v[j];
                } else if (s[i] && !t[j]) { // | &
                    if (u[i] < v[j]) return cout << -1 << endl, 0;
                    a[i][j] = v[j];
                } else if (!s[i] && t[j]) { // & |
                    if (u[i] > v[j]) return cout << -1 << endl, 0;
                    a[i][j] = u[i];
                } else if (!s[i] && !t[j]) { // & &
                    a[i][j] = u[i]|v[j];
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (s[i] && a[i][j]) u[i] = 0;
            }
            for (int j = 1; j <= n; ++j) {
                if (t[i] && a[j][i]) v[i] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            int cntu = 0, cntv = 0;
            for (int j = 1; j <= n; ++j) {
                if (t[j] && v[j] && cntv+1 < n) {
                    a[i][j] = 1;
                    ++cntv;
                }
            }
            for (int j = 1; j <= n; ++j) {
                if (s[j] && u[j] && cntu+1 < n) {
                    a[j][i] = 1;
                    ++cntu;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            unsigned long long sum;
            sum = a[i][1];
            for (int j = 2; j <= n; ++j) {
                if (s[i]) sum |= a[i][j];
                else sum &= a[i][j];
            }
            if (((uu[i]>>b)&1)^sum) return cout << -1 << endl, 0;
            sum = a[1][i];
            for (int j = 2; j <= n; ++j) {
                if (t[i]) sum |= a[j][i];
                else sum &= a[j][i];
            }
            if (((vv[i]>>b)&1)^sum) return cout << -1 << endl, 0;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j]) res[i][j] |= 1<<b;
            }
        }
    }
    // output
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << res[i][j] << " \n"[j==n];
        }
    }
    return 0;
}