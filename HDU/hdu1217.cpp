#include <bits/stdc++.h>

using namespace std;

const int N = 40;
const int M = 1e3+7;

int T, n, m;
map<string, int> name;
int v[M], fir[N], nex[M], vis[N], check[N];
double w[M], dfn[N];

bool dfs(int u, double mul)
{
    if (vis[u]) return mul/dfn[u] > 1;
    dfn[u] = mul;
    vis[u] = 1;
    check[u] = 1;
    for (int i = fir[u]; i; i = nex[i]) {
        if (dfs(v[i], mul*w[i])) return true;
    }
    vis[u] = 0;
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        string str;
        name.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> str;
            name[str] = i;
            fir[i] = vis[i] = check[i] = 0;
        }
        cin >> m;
        for (int i = 1, u; i <= m; ++i) {
            cin >> str; u = name[str];
            cin >> w[i];
            cin >> str; v[i] = name[str];
            nex[i] = fir[u];
            fir[u] = i;
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (check[i]) continue;
            if ((flag |= dfs(i, 1))) break;
        }
        cout << "Case " << ++T << ": " << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
