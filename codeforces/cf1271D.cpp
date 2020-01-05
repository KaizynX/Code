#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n, m, k;
vector<int> e[N];
int a[N], b[N], c[N], f[N], cnt[N];
int dp[N][N];

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    cnt[0] = k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", a+i, b+i, c+i);
        f[i] = i;
        // cnt[i] after i max people can get
        cnt[i] = cnt[i-1]+b[i];
    }
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        // f[i] at pos f[i] choose i
        f[v] = max(f[v], u);
    }

    for (int i = n; i; --i) {
        e[f[i]].emplace_back(c[i]);
        if (cnt[i-1] < a[i]) return puts("-1")&0;
        // cnt[i] max people can choose from[1, i]
        if (i == n) cnt[i] = cnt[i];
        else cnt[i] = min(cnt[i+1], cnt[i]-a[i+1]);
    }
    
    for (int i = 1; i <= n; ++i) {
        sort(e[i].begin(), e[i].end());
        reverse(e[i].begin(), e[i].end());
        // choose j's at i, choose k's before i
        for (int j = 0, sum = 0; j <= (int)e[i].size(); ++j) {
            if (j) sum += e[i][j-1];
            for (int k = 0; k+j <= cnt[i]; ++k) {
                dp[i][k+j] = max(dp[i][k+j], dp[i-1][k]+sum);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= cnt[n]; ++i)
        res = max(res, dp[n][i]);
    printf("%d\n", res);
    return 0;
}
