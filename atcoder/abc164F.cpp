/*
 * @Author: Kaizyn
 * @Date: 2020-04-28 17:22:11
 * @LastEditTime: 2020-04-28 17:59:52
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
unsigned long long a[N][N];

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> s[i];
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) cin >> u[i], uu[i] = u[i];
    for (int i = 1; i <= n; ++i) cin >> v[i], vv[i] = v[i];

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i] && t[j]) { // | |
                a[i][j] = u[i]&v[j];
            } else if (s[i] && !t[j]) { // | &
                if ((u[i]&v[j]) < v[j]) return cout << -1 << endl, 0;
                a[i][j] = v[j];
            } else if (!s[i] && t[j]) { // & |
                if ((u[i]&v[j]) < u[i]) return cout << -1 << endl, 0;
                a[i][j] = u[i];
            } else if (!s[i] && !t[j]) { // & &
                a[i][j] = u[i]|v[j];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        unsigned long long sum = 0;
        for (int j = 1; j <= n; ++j) sum |= a[i][j];
        if (s[i]) u[i] -= sum;
        sum = 0;
        for (int j = 1; j <= n; ++j) sum |= a[j][i];
        if (t[i]) v[i] -= sum;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i] && t[j]) { // | |
                unsigned long long tmp = (uu[i]&v[j])|(u[i]&vv[j]);
                a[i][j] |= tmp;
                u[i] &= ~tmp;
                v[j] &= ~tmp;
            } else if (s[i] && !t[j]) { // | &
                a[i][j] |= u[i];
                u[i] = 0;
            } else if (!s[i] && t[j]) { // & |
                a[i][j] |= v[j];
                v[j] = 0;
            } else if (!s[i] && !t[j]) { // & &
                continue;
            }
        }
    }
    // check
    for (int i = 1; i <= n; ++i) {
        unsigned long long sum;
        sum = a[i][1];
        for (int j = 2; j <= n; ++j) {
            if (s[i]) sum |= a[i][j];
            else sum &= a[i][j];
        }
        if (uu[i] != sum) return cout << -1 << endl, 0;
        sum = a[1][i];
        for (int j = 2; j <= n; ++j) {
            if (t[i]) sum |= a[j][i];
            else sum &= a[j][i];
        }
        if (vv[i] != sum) return cout << -1 << endl, 0;
    }
    // output
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << a[i][j] << " \n"[j==n];
        }
    }
    return 0;
}