#include <bits/stdc++.h>

using namespace std;

const int N = 150000+7;
const int M = 3e2+7;

int n, m, d, head, tail;
int a[2], b[2], t[2], q[N];
long long dp[2][N];

int main()
{
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i&1] >> b[i&1] >> t[i&1];
        long long dis = 1ll*d*(t[i&1]-t[i&1^1]);

        head = tail = 0;
        for (int j = 1; j <= min(1ll*n, dis); ++j) {
            while (head < tail && dp[i&1^1][q[tail]] <= dp[i&1^1][j]) --tail;
            q[++tail] = j;
        }
        for (int j = 1; j <= n; ++j) {
            while (head < tail && q[head+1] < j-dis) ++head;
            if (j+dis <= n) {
                while (head < tail && dp[i&1^1][q[tail]] <= dp[i&1^1][j+dis]) --tail;
                q[++tail] = static_cast<int>(j+dis);
            }
            dp[i&1][j] = dp[i&1^1][q[head+1]]+b[i&1]-abs(a[i&1]-j);
        }
    }
    long long res = dp[m&1][1];
    for (int i = 2; i <= n; ++i)
        res = max(res, dp[m&1][i]);
    cout << res << endl;
    return 0;
}
