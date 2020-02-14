#include <bits/stdc++.h>

using namespace std;

const int N = 40;
const int M = 1e3+7;

int T, n, m;
map<string, int> name;
double f[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n) {
        string str;
        name.clear();
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; ++i) {
            cin >> str;
            name[str] = i;
        }
        cin >> m;
        double w, res = 0.0;
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> str; u = name[str];
            cin >> w;
            cin >> str; v = name[str];
            f[u][v] = w;
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    if (!(k == i && k == j))
                        f[i][j] = max(f[i][j], f[i][k]*f[k][j]);
        for (int i = 1; i <= n; ++i)
            res = max(res, f[i][i]);
        cout << "Case " << ++T << ": " << (res > 1.0 ? "Yes" : "No") << endl;
    }
    return 0;
}
