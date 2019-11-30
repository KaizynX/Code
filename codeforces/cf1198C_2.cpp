#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const int M = 5e5+7;

int T, n, m;
int vis[N], k[N];
vector<int> co[N];

struct Edge
{
    int u, v, w, id;
    friend bool operator < (const Edge &x, const Edge &y) {
        return x.w < y.w;
    }
    friend istream &operator >> (istream &is, Edge &x) {
        is >> x.u >> x.v;
        return is;
    }
} e[M];

inline bool cmp(const int x, const int y) {
    return co[x].size() < co[y].size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    vector<int> res;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i) {
            cin >> e[i];
            e[i].id = i;
            co[e[i].u].emplace_back(e[i].v);
            co[e[i].v].emplace_back(e[i].u);
        }
        for (int i = 1; i <= m; ++i) {
            e[i].w = co[e[i].u].size()+co[e[i].v].size();
        }
        sort(e+1, e+m+1);
        res.clear();
        for (int i = 1; i <= 3*n; ++i) vis[i] = 0;
        for (int i = 1; i <= m; ++i) {
            if (!vis[e[i].u] && !vis[e[i].v]) {
                vis[e[i].u] = 1;
                vis[e[i].v] = 1;
                res.emplace_back(e[i].id);
            }
        }
        if ((int)res.size() >= n) {
            cout << "Matching" << endl;
            for (int i = 0; i < n; ++i)
                cout << res[i] << " ";
            cout << endl;
        } else {
            cout << "IndSet" << endl;
            for (int i = 1, cnt = 0; i <= n*3; ++i) {
                if (!vis[i]) {
                    cout << i << " ";
                    if (++cnt >= n) break;
                }
            }
            cout << endl;
        }
        /*
        res.clear();
        for (int i = 1; i <= n*3; ++i) vis[i] = 0, k[i] = i;
        sort(k+1, k+n*3+1, cmp);
        for (int i = 1; i <= n*3; ++i) {
            if (vis[k[i]]) continue;
            res.emplace_back(k[i]);
            for (int j : co[k[i]]) vis[j] = 1;
        }
        if ((int)res.size() >= n) {
            cout << "IndSet" << endl;
            for (int i = 0; i < n; ++i)
                cout << res[i] << " ";
            cout << endl;
            continue;
        }
        cout << "Impossible" << endl;
        */
    }
    return 0;
}
