#include <bits/stdc++.h>

using namespace std;

const int N = 150000+7;
const int M = 3e2+7;

int n, m, d, head, tail;
int a[M], b[M], t[M], q[N];
long long dp[M][N];

int main()
{
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> t[i];
        long long dis = d*(t[i]-t[i-1]);

        head = tail = 0;
        for (int j = 1; j <= min(1ll*n, dis); ++j) {
            while (head < tail && dp[i-1][q[tail]] <= dp[i-1][j]) --tail;
            q[++tail] = j;
        }
        for (int j = 1; j <= n; ++j) {
            while (head < tail && q[head+1] < j-dis) ++head;
            if (j+dis <= n) {
                while (head < tail && dp[i-1][q[tail]] <= dp[i-1][j+dis]) --tail;
                q[++tail] = static_cast<int>(j+dis);
            }
            dp[i][j] = dp[i-1][q[head+1]]+b[i]-abs(a[i]-j);
        }
    }
    long long res = dp[m][1];
    for (int i = 2; i <= n; ++i)
        res = max(res, dp[m][i]);
    cout << res << endl;
    return 0;
}
