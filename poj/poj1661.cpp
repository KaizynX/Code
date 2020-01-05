#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e3+7;
const int INF = 0x7f7f7f7f;

int T, n, bx, by, mh;
int dp[2][N];

struct Node
{
    int l, r, h;
    friend bool operator < (const Node &x, const Node &y) {
        return x.h > y.h;
    }
    friend istream &operator >> (istream &is, Node &x) {
        return is >> x.l >> x.r >> x.h;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> bx >> by >> mh;
        a[0].l = a[0].r = bx;
        a[0].h = by;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a+1, a+n+1);
        memset(dp[0], 0x7f, sizeof(int)*(n+3));
        memset(dp[1], 0x7f, sizeof(int)*(n+3));
        dp[0][0] = dp[1][0] = 0;

        int res = INF;
        for (int i = 0, flag; i <= n; ++i) {
            flag = 0;
            for (int j = i+1; j <= n && a[i].h-a[j].h <= mh; ++j) {
                if (a[i].l >= a[j].l && a[i].l <= a[j].r) {
                    dp[0][j] = min(dp[0][j], dp[0][i]+a[i].l-a[j].l);
                    dp[1][j] = min(dp[1][j], dp[0][i]+a[j].r-a[i].l);
                    flag = 1;
                    break;
                }
            }
            if (!flag && a[i].h <= mh) res = min(res, dp[0][i]);
            flag = 0;
            for (int j = i+1; j <= n && a[i].h-a[j].h <= mh; ++j) {
                if (a[i].r >= a[j].l && a[i].r <= a[j].r) {
                    dp[0][j] = min(dp[0][j], dp[1][i]+a[i].r-a[j].l);
                    dp[1][j] = min(dp[1][j], dp[1][i]+a[j].r-a[i].r);
                    flag = 1;
                    break;
                }
            }
            if (!flag && a[i].h <= mh) res = min(res, dp[1][i]);
        }
        cout << res+by << endl;
    }
    return 0;
}
