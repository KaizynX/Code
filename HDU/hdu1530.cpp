#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int g[N][N];

struct MaxClique
{
    vector<int> res, tmp, cnt;
    bool dfs(int p) {
        for (int i = p+1, flag; i <= n; ++i) {
            if (cnt[i]+tmp.size() <= res.size()) return false;
            if (!g[p][i]) continue;
            flag = 1;
            for (int j : tmp)
                if (!g[i][j]) flag = 0;
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
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &g[i][j]);
        MC.solve();
        printf("%d\n", MC.res.size());
    }
    return 0;
}
