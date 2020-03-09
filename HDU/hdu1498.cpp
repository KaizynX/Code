#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, k;
int a[N][N], e[N][N], co[N], vis[N];
vector<int> ans;

bool check(int u)
{
    for (int v = 1; v <= n; ++v) if (e[u][v]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (!co[v] || check(co[v])) {
            co[v] = u;
            return true;
        }
    }
    return false;
}

inline int solve()
{
    int res = 0;
    memset(co, 0, sizeof co);
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(int)*(n+3));
        res += check(i);
    }
    return res;
}

int main()
{
    while (cin >> n >> k && n|k) {
        vector<int>().swap(ans);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        for (int c = 1, cnt; c <= 50; ++c) {
            cnt = 0;
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    cnt += e[i][j] = (a[i][j] == c);
            if (!cnt) continue;
            if (solve() > k) ans.emplace_back(c);
        }
        if (!ans.size()) cout << -1 << endl;
        else {
            for (unsigned i = 0; i < ans.size(); ++i)
                cout << ans[i] << " \n"[i+1 == ans.size()];
        }
    }
    return 0;
}
