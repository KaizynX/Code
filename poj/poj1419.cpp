#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e2+7;

int T, n, m;
int g[N][N];

struct MaxClique
{
    vector<int> res, tmp, cnt;
    bool dfs(int p) {
        for (int i = p+1, flag; i <= n; ++i) {
            if (cnt[i]+tmp.size() <= res.size()) return false;
            if (g[p][i]) continue;
            flag = 1;
            for (int j = 0; j < (int)tmp.size(); ++j)
                if (g[i][tmp[j]]) flag = 0;
            if (!flag) continue;
            tmp.push_back(i);
            if (dfs(i)) return true;
            tmp.pop_back();
        }
        if (tmp.size() > res.size()) {
            res = tmp;
            return true;
        }
        return false;
    }
    void solve() {
        vector<int>(n+1, 0).swap(cnt);
        vector<int>().swap(res);
        for (int i = n; i; --i) {
            vector<int>(1, i).swap(tmp);
            dfs(i);
            cnt[i] = res.size();
        }
    }
} MC;

int main()
{
    scanf("%d", &T);
    while (T--) {
        memset(g, 0, sizeof g);
        scanf("%d %d", &n, &m);
        for (int i = 1, u, v; i <= m; ++i) {
            scanf("%d %d", &u, &v);
            g[u][v] = g[v][u] = 1;
        }
        MC.solve();
        printf("%d\n", MC.res.size());
        for (int i = 0; i < (int)MC.res.size(); ++i)
            printf("%d%c", MC.res[i], " \n"[i+1 == (int)MC.res.size()]);
    }
    return 0;
}
