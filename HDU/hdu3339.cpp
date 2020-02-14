#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int V = 1e4+7;

int T, n, m, sum;
int a[N], f[N][N], dp[V];

inline void update(int &x, const int y) { if (x == -1 || x > y) x = y; }

inline void init()
{
    sum = 0;
    memset(f, -1, sizeof f);
    memset(dp, -1, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i <= n; ++i) f[i][i] = 0;
}

inline void floyd()
{
    for (int k = 0; k <= n; ++k)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                if (f[i][k] != -1 && f[k][j] != -1)
                    update(f[i][j], f[i][k]+f[k][j]);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        init();
        cin >> n >> m;
        for (int i = 1, u, v, w; i <= m; ++i) {
            cin >> u >> v >> w;
            update(f[u][v], w);
            update(f[v][u], w);
        }
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        floyd();
#ifdef DEBUG
        for (int i = 1; i <= n; ++i)
            cout << f[0][i] << " \n"[i==n];
#endif
        for (int i = 1; i <= n; ++i) if (f[0][i] != -1)
            for (int j = sum; j >= a[i]; --j)
                if (dp[j-a[i]] != -1)
                    update(dp[j], dp[j-a[i]]+f[0][i]);
        int res = -1;
        for (int i = sum/2+1; i <= sum; ++i)
            if (dp[i] != -1)
                update(res, dp[i]);
        if (res == -1) cout << "impossible" << endl;
        else cout << res << endl;
    }
}
