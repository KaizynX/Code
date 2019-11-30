#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int T, n, m, res;
int d[N], dp[N][N];

struct Node
{
    vector<int> p;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.p > n2.p;
    }
    friend istream &operator >> (istream &is, Node &n0) {
        n0.p.resize(3);
        for (int i = 0; i < 3; ++i)
            is >> n0.p[i];
        return is;
    }
} a[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        ++T;
        res = m = 0;
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sort(a[i].p.begin(), a[i].p.end());
            for (int j = 0; j < 3; ++j)
                d[++m] = a[i].p[j];
        }
        sort(d+1, d+m+1);
        m = unique(d+1, d+m+1)-d-1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < 3; ++j)
                a[i].p[j] = lower_bound(d+1, d+m+1, a[i].p[j])-d;
        for (int i = 1, sz = n; i <= sz; ++i) {
            do {
                a[++n] = a[i];
            } while (next_permutation(a[i].p.begin(), a[i].p.end()));
        }
        sort(a+1, a+n+1);
        for (int k = 1, x, y, z; k <= n; ++k) {
            x = a[k].p[0]; y = a[k].p[1]; z = a[k].p[2];
            for (int i = m+1; i > x; --i)
                for (int j = m+1; j > y; --j)
                    dp[x][y] = max(dp[x][y], dp[i][j]+d[z]);
            res = max(res, dp[x][y]);
        }
        cout << "Case " << T << ": maximum height = " << res << endl;
    }
    return 0;
}
