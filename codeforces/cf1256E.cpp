#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int INF = 0x3f3f3f3f;

int n;
int t[N], dp[N][N], last[N][N];

struct Node
{
    int v, id;
    friend bool operator < (const Node &x, const Node &y) {
        return x.v < y.v;
    }
} a[N];

int main()
{
    cin >> n;
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].v;
        a[i].id = i;
    }
    sort(a+1, a+n+1);
    int res = (n-1)/5+1;
    for (int i = 0; i <= n; ++i) dp[0][i] = dp[i][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = (i-1)/5+1; j <= (i-1)/3+1; ++j) {
            for (int k = max((j-1)*3, i-5); k <= min((j-1)*5, i-3); ++k) {
                // dp[i][j] = min(dp[i][j], dp[k][j-1]+a[i].v-a[k+1].v);
                if (dp[i][j] > dp[k][j-1]+a[i].v-a[k+1].v) {
                    dp[i][j] = dp[k][j-1]+a[i].v-a[k+1].v;
                    last[i][j] = k;
                }
            }
            if (n == i && dp[n][j] < dp[n][res]) res = j;
        }
    }
    for (int i = n, j = res; i && j; i = last[i][j], --j) {
        for (int k = i; k > last[i][j]; --k) {
            t[a[k].id] = j;
        }
    }

    cout << dp[n][res] << " " << res << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (t[i] ? t[i] : 1) << " \n"[i==n];
    }
    return 0;
}
