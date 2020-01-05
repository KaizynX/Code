#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 3e3+37;

int D, n;
int dp[N][M];

struct Node
{
    int t, f, h;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.t < n2.t;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.t >> node.f >> node.h;
    }
} a[N];

int main()
{
    cin >> D >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    memset(dp, -1, sizeof dp);
    for (int i = 0; i <= 10; ++i) dp[0][i] = 0;
    for (int i = 1, t, f, h; i <= n; ++i) {
        t = a[i].t; f = a[i].f; h = a[i].h;
        memcpy(dp[i], dp[i-1], sizeof(dp[i]));
        for (int j = 3000; j >= t; --j) {
            if (dp[i-1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i-1][j]+h);
                dp[i][j+f] = max(dp[i][j+f], dp[i-1][j]);
            }
        }
    }
    int res = -1, sumf = -1;
    for (int i = 0; i <= 3000; ++i) {
        if (dp[n][i] != -1) sumf = max(sumf, i);
        if (dp[n][i] >= D) {
            res = i;
            break;
        }
    }
    cout << (res == -1 ? sumf : res) << endl;
    return 0;
}
