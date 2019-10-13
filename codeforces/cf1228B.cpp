#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;

int n, m, cnt;
int r[N], c[N], a[N][N];

inline int qpow(int a, int p)
{
    int res = 1;
    while (p) {
        if (p&1) res = static_cast<int>(1ll*res*a%MOD);
        a = static_cast<int>(1ll*a*a%MOD);
        p >>= 1;
    }
    return res;
}

int main()
{
    memset(a, -1, sizeof a);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
        for (int j = 1; j <= r[i]; ++j) {
            a[i][j] = 1;
        }
        if (r[i]+1 <= m) a[i][r[i]+1] = 0;
    }
    for (int j = 1; j <= m; ++j) {
        cin >> c[j];
        for (int i = 1; i <= c[j]; ++i) {
            if (a[i][j] == 0) {
                cout << 0 << endl;
                return 0;
            }
            a[i][j] = 1;
        }
        if (c[j]+1 <= n) {
            if (a[c[j]+1][j] == 1) {
                cout << 0 << endl;
                return 0;
            }
            a[c[j]+1][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == -1) ++cnt;
        }
    }
    cout << qpow(2, cnt) << endl;
    return 0;
}
