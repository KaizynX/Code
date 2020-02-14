#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 1e9;

int n, s, t, m;
int f[N][N];
string str;
map<string, int> name;

inline void init()
{
    name.clear();
    m = 0;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= 200; ++i) f[i][i] = 0;
}

inline int id(const string &sss)
{
    if (name.find(sss) == name.end()) return name[sss] = ++m;
    else return name[sss];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n && n != -1) {
        init();
        cin >> str; s = id(str);
        cin >> str; t = id(str);
        for (int i = 1, u, v, w; i <= n; ++i) {
            cin >> str;
            u = id(str);
            cin >> str;
            v = id(str);
            cin >> w;
            if (f[u][v] != -1) w = min(w, f[u][v]);
            f[u][v] = f[v][u] = w;
        }
        for (int k = 1; k <= m; ++k)
            for (int i = 1; i <= m; ++i)
                for (int j = 1; j <= m; ++j)
                    if (f[i][k] != -1 && f[k][j] != -1 &&
                        (f[i][j] == -1 || f[i][k]+f[k][j] < f[i][j]))
                        f[i][j] = f[i][k]+f[k][j];
        cout << f[s][t] << endl;
    }
    return 0;
}
