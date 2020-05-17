/*
 * @Author: Kaizyn
 * @Date: 2020-05-08 23:47:23
 * @LastEditTime: 2020-05-09 00:04:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int NN = sqrt(N)+7;

struct FenKuai
{
    typedef int T;
    int t; // 每组大小
    T a[N], b[N], add[N];

    FenKuai()
    {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        memset(add, 0, sizeof add);
    }

    void build(int x)
    {
        for (int i = x*t; i < min(x*t+t, n); ++i) b[i] = a[i];
        sort(b+x*t, b+min(x*t+t, n));
    }

    void init()
    {
        t = static_cast<int>(sqrt(n)+0.5);
        for (int i = 0; i*t < n; ++i) build(i);
    }

    void update(int x, int y, T c)
    {
        int i = x;
        for ( ; i <= y && i%t; ++i) a[i] += c;
        build(x/t);
        for ( ; i+t-1 <= y; i += t) add[i/t] += c;
        for ( ; i <= y; ++i) a[i] += c;
        build(y/t);
    }

    T query(int x, int y, long long c)
    {
        T res = 0; int i = x;
        for ( ; i <= y && i%t; ++i) res += (a[i]+add[i/t] < c*c);
        for ( ; i+t-1 <= y; i += t) res += lower_bound(b+i, b+i+t, c*c-add[i/t])-(b+i);
        for ( ; i <= y; ++i) res += (a[i]+add[i/t] < c*c);
        return res;
    }
} B;

int n, m, q, t;
int col[N];
int num[N][NN];
long long val[NN][NN][2][2];
long long res[2][2];

inline void add(const int &u, const int &v, const int &w) {
    int x = u/t, y = v/t;
    ++num[x][y][col[u]][col[v]];
    ++num[y][x][col[v]][col[u]];
    val[x][y][col[u]][col[v]] += w;
    val[y][x][col[v]][col[u]] += w;
    res[col[u]][col[v]] += w;
    res[col[v]][col[u]] += w;
}

inline void update(const int &x) {
    int b = x/t;
    for (int i = 0; i <= n/t; ++i) {
    }
}

inline void solve() {
    static char ask[10];

    t = static_cast<int>(sqrt(n)+.5);
    memset(res, 0, sizeof res);
    for (int i = 0; i <= n/t; ++i) {
        memset(num[i][j], 0, sizeof(num[i][j]));
        for (int j = 0; j <= n/t; ++j) {
            memset(val[i][j], 0, sizeof(val[i][j]));
        }
    }

    for (int i = 1; i <= n; ++i) scanf("%d", col+i);
    for (int i = 1, u, v, w; i <= m; ++i) {
        scanf("%d %d %d", &u, &v, &w);
        add(--u, --v, w);
    }
    scanf("%d", &q);
    for (int i = 1, x, l, r; i <= q; ++i) {
        scanf("%s", ask);
        if (ask[0] == 'A') {
            scanf("%d %d", &l, &r);
            printf("%lld\n", res[l][r]);
        } else {
            scanf("%d", &x);
            update(--x);
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0;
    while (scanf("%d %d", &n, &m) == 2) {
        printf("Case %d:\n", ++T);
        solve();
    }
    return 0;
}