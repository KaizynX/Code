#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n, m;
int a[N], f[N][N], p[N][N];

void print(int u, int v)
{
    if (!p[u][v]) return;
    print(u, p[u][v]);
    cout << p[u][v] << "->";
    print(p[u][v], v);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        memset(f, 0, sizeof f);
        memset(p, 0, sizeof p);
        cin >> n;
        a[4] = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            f[u][v] = 1;
        }
        cout << "CASE " << t << "#\n"
             << "points : " << f[1][4] << "\n"
             << "circuit : 1->";
        print(1, n+1);
        cout << "1\n";
    }
    return 0;
}
