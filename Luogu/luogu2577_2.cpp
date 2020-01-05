#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;

int n;
// dp[i][j] i's people in first line cost j time 
int dp[2][N*N], s[N];

struct Node
{
    int t1, t2;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.t2 > n2.t2;
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.t1 >> node.t2;
    }
} a[N];

inline void update(int &x, const int y) { if (x == -1 || y < x) x = y; }

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i-1]+a[i].t1;
        memset(dp[i&1], -1, sizeof dp[i]);
        for (int k = 0; k <= s[i]; ++k) {
            if (dp[i&1^1][k] != -1)
                update(dp[i&1][k], max(dp[i&1^1][k], s[i]-k+a[i].t2));
            if (k-a[i].t1 >= 0 && dp[i&1^1][k-a[i].t1] != -1)
                update(dp[i&1][k], max(dp[i&1^1][k-a[i].t1], k+a[i].t2));
#ifdef DEBUG
            printf("[%d][%d] %d\n", i, j, k, dp[i&1][k]);
#endif
        }
    }
    int res = -1;
    for (int j = 0; j <= s[n]; ++j) {
        if (dp[n&1][j] != -1)
            update(res, dp[n&1][j]);
    }
    cout << res << endl;
    return 0;
}
