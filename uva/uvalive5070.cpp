/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 18:57:27
 * @LastEditTime: 2020-03-26 20:13:31
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 27;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

// -1 : no solution, 0 : multi , 1 : one
template <typename T>
int XorGauss(T a[N], const int &n)
{
    for (int i = 1, j, k; i <= n; ++i) {
        for (k = i; !a[k][i] && k <= n; ++k) {}
        if (k <= n) swap(a[k], a[i]);
        for (j = 1; j <= n; ++j) if (i != j && a[j][i])
            for (k = i; k <= n+1; ++k) a[j][k] ^= a[i][k];
            // a[j] ^= a[i]; // bitset<N> a[N]
    }
    for (int i = 1; i <= n; ++i) if (!a[i][i]) return -a[i][n+1];
    return 1;
}

int n, m, d;
int a[N][N], b[N*N][N*N];

inline int mp(const int &x, const int &y) { return (x-1)*m+y; }

// a[i][j] == 0 off, ask whether could turn all off
inline void solve()
{
    for (int i = 1; i <= n*m; ++i)
        for (int j = 1; j <= n*m+1; ++j)
            b[i][j] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b[mp(i, j)][n*m+1] = a[i][j];
            b[mp(i, j)][mp(i, j)] = 1;
            for (int x = 1; x <= n; ++x) {
                for (int y = 1; y <= m; ++y) {
                    if (abs(x-i)+abs(y-j) == d)
                        b[mp(i, j)][mp(x, y)] = 1;
                }
            }
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= n*m; ++i) {
        for (int j = 1; j <= n*m+1; ++j) {
            cout << b[i][j] << " \n"[j==n*m+1];
        }
    }
    #endif
    puts((XorGauss(b, n*m) == -1 ? "0" : "1"));
}

signed main()
{
    while (scanf("%d %d %d", &m, &n, &d) == 3 && n|m|d) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        solve();
    }
    return 0;
}