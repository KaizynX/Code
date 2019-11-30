#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int INF = 1e9;

int n;
int dp[N][12];

struct Node
{
    int x, t;
    friend bool operator < (const Node &x, const Node &y) {
        return x.t < y.t;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.x >> node.t;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i <= 10; ++i) if (i != 5) dp[0][i] = -INF;
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        for (int i = 1, p = 1; i <= a[n].t; ++i) {
            for (int j = 0; j <= 10; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j-1 >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                if (j+1 <= 10) dp[i][j] = max(dp[i][j], dp[i-1][j+1]);
            }
            while (p <= n && a[p].t == i)
                ++dp[i][a[p++].x];
        }
        int res = 0;
        for (int j = 0; j <= 10; ++j)
            res = max(res, dp[a[n].t][j]);
        cout << res << endl;
    }
    return 0;
}
