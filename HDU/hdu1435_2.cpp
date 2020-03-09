#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
typedef pair<int, int> pii;

template <typename T> struct Stable_marriage
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
                 [&](const int &x, const int &y) { return wb[i][x] < wb[i][y]; });
            sort(rkg[i]+1, rkg[i]+n+1,
                 [&](const int &x, const int &y) { return wg[i][x] < wg[i][y]; });
        }
    }
    bool match(const int &x, const int &y) {
        int xx = g[y];
        if (g[y]) {
            if (wg[y][x] < wg[y][xx])
                return false;
            q.push(xx);
        }
        b[x] = y;
        g[y] = x;
        return true;
    }
    void gale_shapely(const int &n) {
        init();
        while (q.size()) {
            int x = q.front();
            q.pop();
            int y = rkb[x][++t[x]];
            if (!match(x, y))
                q.push(x);
        }
    }
};

int main()
{
    return 0;
}
