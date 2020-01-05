#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 5e3+7;

int n;
int a[N], b[N];
int mem[N][M<<1], *dp[N];

inline void update(int &x, const int &y) { if (x == -1 || x > y) x = y; }

int main()
{
    for (int i = 0; i < N; ++i) dp[i] = mem[i]+M;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    memset(mem, -1, sizeof mem);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = -5000; j <= 5000; ++j)
            if (dp[i-1][j] != -1) {
                update(dp[i][j+a[i]-b[i]], dp[i-1][j]);
                update(dp[i][j-a[i]+b[i]], dp[i-1][j]+1);
            }
    }
    int res;
    for (int i = 0; i <= 5000; ++i) {
        if (dp[n][i] == -1 && dp[n][-i] == -1) continue;

        if (dp[n][i] == -1) res = dp[n][-i];
        else if (dp[n][-i] == -1) res = dp[n][i];
        else res = min(dp[n][i], dp[n][-i]);
        break;
    }
    cout << res << endl;
    return 0;
}
