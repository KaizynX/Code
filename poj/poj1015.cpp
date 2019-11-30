#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e2+7;
const int M = 2e1+7;
const int INF = 1e9;

int T, n, m;
// dp[i][j] from[1, i] (i'th must choose) choose j's min abs
int dp[N][M], sum[N][M], last[N][M];

struct Node
{
    int d, p, id;
    friend bool operator < (const Node &x, const Node &y) {
        return abs(x.d-x.p) > abs(y.d-y.p);
    }
    friend istream &operator >> (istream &is, Node &x) {
        return is >> x.p >> x.d;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m && n|m) {
        ++T;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            a[i].id = i;
        }
        sort(a+1, a+n+1);
        memset(dp, 0x3f, sizeof dp);
        memset(sum, 0, sizeof sum);
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m && j <= i; ++j) {
                dp[i][j] = INF;
                for (int k = 0; k < i; ++k) {
                    int dis = dp[k][j-1]+a[i].d-a[i].p,
                        tmp = sum[k][j-1]+a[i].d+a[i].p;
                    if (abs(dis) < abs(dp[i][j])
                        || (abs(dis) == abs(dp[i][j]) && sum[i][j] < tmp)) {
                        dp[i][j] = dis;
                        sum[i][j] = tmp;
                        last[i][j] = k;
                    }
                }
            }
        }
        int resi = 0;
        for (int i = 1; i <= n; ++i) {
            if (abs(dp[i][m]) < abs(dp[resi][m])
                || (abs(dp[i][m]) == abs(dp[resi][m]) && sum[i][m] > sum[resi][m])) {
                resi = i;
            }
        }
        vector<int> path;
        int sump = 0, sumd = 0;
        for (int i = resi, j = m; i && j; i = last[i][j--]) {
            sump += a[i].p;
            sumd += a[i].d;
            path.push_back(a[i].id);
        }
        sort(path.begin(), path.end());
        cout << "Jury #" << T << endl
             << "Best jury has value " << sump
             << " for prosecution and value " << sumd
             << " for defence: " << endl;
        for (int i = 0; i < (int)path.size(); ++i)
            cout << " " << path[i];
        cout << endl << endl;
    }
    return 0;
}
