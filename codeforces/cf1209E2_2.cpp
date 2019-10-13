#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 12;
const int M = 2e3+7;

int t, n, m;
int a[N][M], dp[2][1<<N], lg[1<<N], tmp[1<<N], tag[M];

struct Column
{
    int mv = 0, id;
    bool operator < (const Column &nex) const { return mv > nex.mv; }
} c[M];

inline void solve()
{
    cin >> n >> m;
    // init
    for (int j = 0; j < m; ++j) {
        c[j].id = j;
        c[j].mv = 0;
        tag[j] = 0;
    }
    for (int k = 0; k < (1<<n); ++k)
        dp[0][k] = dp[1][k] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            c[j].mv = max(c[j].mv, a[i][j]);
        }
    }
    sort(c, c+m);
    // nth_element(c, c+min(n, m), c+m);
    for (int i = 0; i < min(n, m); ++i)
        tag[c[i].id] = 1;
    // col
    for (int j = 0; j < m; ++j) {
        if (!tag[j]) continue;
        for (int k = 0; k < (1<<n); ++k) dp[j&1][k] = 0;
        // rotate
        for (int r = 0; r < n; ++r) {
            for (int k = 0; k < (1<<n); ++k) tmp[k] = dp[j&1^1][k];
            for (int k = 0; k < (1<<n); ++k) {
                int p = ((1<<n)-1)^k;
                while (p) {
                    int x = p&-p, y = lg[x];
                    p -= x;
                    tmp[k|x] = max(tmp[k|x], tmp[k]+a[(y+r)%n][c[j].id]);
                }
            }
            for (int k = 0; k < (1<<n); ++k) dp[j&1][k] = max(dp[j&1][k], tmp[k]);
        }
#ifdef DEBUG
        for (int k = 0; k < (1<<n); ++k)
            cout << dp[j&1][k] << " ";
        cout << endl;
#endif
    }

    cout << dp[min(n, m)&1][(1<<n)-1] << endl;
}

int main()
{
    cin >> t;
    for (int i = 0; i < N; ++i) lg[1<<i] = i;
    while (t--) {
        solve();
    }
    return 0;
}
