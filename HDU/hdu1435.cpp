#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e2+7;

int T, n;

struct Station
{
    int id, r;
    double x, y, z;
    friend istream& operator >> (istream &is, Station &s) {
        return is >> s.id >> s.r >> s.x >> s.y >> s.z;
    }
    friend double dis(const Station &n1, const Station &n2) {
        return sqrt((n1.x-n2.x)*(n1.x-n2.x)+(n1.y-n2.y)*(n1.y-n2.y)+(n1.z-n2.z)*(n1.z-n2.z));
    }
} a[N], b[N];

struct Node
{
    double d;
    int r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.d == n2.d ? n1.r < n2.r : n1.d > n2.d;
    }
};

template <typename T = int> struct Stable_Marriage
{
    int t[N], b[N], g[N], rkb[N][N], rkg[N][N];
    T wb[N][N], wg[N][N];
    queue<int> q;
    void init(const int &n) {
        queue<int>().swap(q);
        memset(t, 0, sizeof(int)*(n+3));
        memset(b, 0, sizeof(int)*(n+3));
        memset(g, 0, sizeof(int)*(n+3));
        for (int i = 1; i <= n; ++i) {
            q.push(i);
            for (int j = 1; j <= n; ++j)
                rkb[i][j] = rkg[i][j] = j;
            sort(rkb[i]+1, rkb[i]+n+1,
                 [&](const int &x, const int &y) { return wb[i][y] < wb[i][x]; });
            //sort(rkg[i]+1, rkg[i]+n+1,
            //     [&](const int &x, const int &y) { return wg[i][y] < wg[i][x]; });
        }
    }
    bool match(const int &x, const int &y) {
        if (g[y]) {
            if (wg[y][x] < wg[y][g[y]]) return false;
            b[g[y]] = 0;
            q.push(g[y]);
        }
        b[x] = y; g[y] = x;
        return true;
    }
    void gale_shapely(const int &n) {
        init(n);
        while (q.size()) {
            int x = q.front(); q.pop();
            int y = rkb[x][++t[x]];
            if (!match(x, y)) q.push(x);
        }
    }
};
Stable_Marriage<Node> SM;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                SM.wb[a[i].id][b[j].id] = {dis(a[i], b[j]), b[j].r},
                SM.wg[b[i].id][a[j].id] = {dis(b[i], a[j]), a[j].r};
        SM.gale_shapely(n);
        for (int i = 1; i <= n; ++i)
            cout << i << " " << SM.b[i] << endl;
#ifdef DEBUG
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cout << dis(a[i], b[j]) << " \n"[j==n];
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cout << SM.rkb[i][j] << " \n"[j==n];
#endif
    }
    return 0;
}
