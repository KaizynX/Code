#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
typedef pair<int, int> pii;

int n, m, k, q;
int f[N][N], d[N], vis[N];
vector<pii> v;
string s;
stringstream ss;

inline void update(int &x, const int &y) { if (x == -1 || x > y) x = y; }

inline void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][k] != -1 && f[k][j] != -1)
                    update(f[i][j], f[i][k]+f[k][j]);
}

int main()
{
    memset(f, -1, sizeof f);
    cin >> n >> m >> k;
    cin.get();
    for (int i = 1, u, v, w; i <= m; ++i) {
        getline(cin, s);
        ss.clear();
        ss << s;
        ss >> u;
        d[u] = 1;
        while (ss >> w >> v) {
            update(f[u][v], w);
            update(f[v][u], w);
            u = v;
        }
        d[v] = 1;
    }
    floyd();
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        v.clear();
        memset(vis, 0, sizeof vis);
        vis[x] = 1;
        for (int i = 1; i <= n; ++i) {
            if (i == x || f[x][i] == -1) continue;
            v.emplace_back(f[x][i], i);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (int i = 0, pri = -1, dis; i < (int)v.size(); ++i) {
#ifdef DEBUG
            cout << v[i].first << " " << v[i].second << endl;
#endif
            //if (v[i].first/k+(v[i].first%k != 0) != pri) {
            //    pri = v[i].first/k+(v[i].first%k != 0);
            if (v[i].first/k != pri) {
                pri = v[i].first/k;
                dis = v[i].first;
            }
            if (d[v[i].second] || v[i].first == dis)
                vis[v[i].second] = 1;
        }
        for (int i = 1, flag = 0; i <= n; ++i) {
            if (!vis[i]) continue;
            if (flag) cout << " ";
            flag = 1;
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
