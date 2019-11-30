#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 2e2+7;
const int T = 4e4+7;
const int dx[] = { 0, -1, 1, 0, 0 },
          dy[] = { 0, 0, 0, -1, 1 };

int n, m, k, head, tail;
int q[N], a[N][N], dp[2][N][N];

struct Node
{
    int s, t, d;
    friend bool operator < (const Node &x, const Node &y) {
        return x.s < y.s;
    }
    friend istream& operator >> (istream &is, Node &x) {
        is >> x.s >> x.t >> x.d;
        return is;
    }
} b[N];

int main()
{
    char c;
    int bx, by;
    cin >> n >> m >> bx >> by >> k;
    memset(dp, 0xef, sizeof dp);
    dp[0][bx][by] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == '.') a[i][j] = 1;
        }
    }
    for (int i = 1; i <= k; ++i)
        cin >> b[i];
    sort(b+1, b+k+1);
    
    for (int l = 1, len; l <= k; ++l) {
        len = b[l].t-b[l].s+1;
        memcpy(dp[l&1], dp[l&1^1], sizeof dp[0]);
        if (b[l].d == 1) {        // up
            for (int j = 1; j <= m; ++j) {
                head = tail = 0;
                for (int i = n; i; --i) {
                    if (!a[i][j]) { head = tail = 0; continue; }
                    while (head < tail && q[head+1] > i+len) ++head;
                    while (head < tail && dp[l&1^1][q[tail]][j]+q[tail]-i < dp[l&1^1][i][j]) --tail;
                    q[++tail] = i;
                    dp[l&1][i][j] = max(dp[l&1][i][j], dp[l&1^1][q[head+1]][j]+q[head+1]-i);
                }
            }
        } else if (b[l].d == 2) { // down
            for (int j = 1; j <= m; ++j) {
                head = tail = 0;
                for (int i = 1; i <= n; ++i) {
                    if (!a[i][j]) { head = tail = 0; continue; }
                    while (head < tail && q[head+1] < i-len) ++head;
                    while (head < tail && dp[l&1^1][q[tail]][j]+i-q[tail] < dp[l&1^1][i][j]) --tail;
                    q[++tail] = i;
                    dp[l&1][i][j] = max(dp[l&1][i][j], dp[l&1^1][q[head+1]][j]+i-q[head+1]);
                }
            }
        } else if (b[l].d == 3) { // left
            for (int i = 1; i <= n; ++i) {
                head = tail = 0;
                for (int j = m; j; --j) {
                    if (!a[i][j]) { head = tail = 0; continue; }
                    while (head < tail && q[head+1] > j+len) ++head;
                    while (head < tail && dp[l&1^1][i][q[tail]]+q[tail]-j < dp[l&1^1][i][j]) --tail;
                    q[++tail] = j;
                    dp[l&1][i][j] = max(dp[l&1][i][j], dp[l&1^1][i][q[head+1]]+q[head+1]-j);
                }
            }
        } else if (b[l].d == 4) { // right
            for (int i = 1; i <= n; ++i) {
                head = tail = 0;
                for (int j = 1; j <= m; ++j) {
                    if (!a[i][j]) { head = tail = 0; continue; }
                    while (head < tail && q[head+1] < j-len) ++head;
                    while (head < tail && dp[l&1^1][i][q[tail]]+j-q[tail] < dp[l&1^1][i][j]) --tail;
                    q[++tail] = j;
                    dp[l&1][i][j] = max(dp[l&1][i][j], dp[l&1^1][i][q[head+1]]+j-q[head+1]);
                }
            }
        }
#ifdef DEBUG
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                printf("%d%c", dp[l&1][i][j], " \n"[j == m]);
#endif
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            res = max(res, dp[k&1][i][j]);
    cout << res << endl;
    return 0;
}
