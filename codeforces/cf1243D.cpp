#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m;
int flag[N];
vector<int> e[N], _e[N], p[2];
map<pair<int, int>, int> mp;

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    bool connect(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

int main()
{
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int mini = 1;
    for (int i = 2; i <= n; ++i) {
        if (e[i].size() < e[mini].size())
            mini = i;
    }
    // rebuild map
    int id = 0;
    p[id].emplace_back(mini);
    flag[mini] = 1;
    for (int i : e[mini]) {
        p[id].emplace_back(i);
        flag[i] = 1;
    }
    while (p[0].size() != p[1].size()) {
        id ^= 1;
        p[id].clear();
        for (int i : p[id^1]) {
            int tmp = 0;
            for (int j : e[i]) {
                if (!flag[j])
                    ++tmp;
            }
            if (i == mini || tmp == n-(int)p[id^1].size()) {
                p[id].emplace_back(i);
            } else {
                flag[i] = 0;
            }
        }
#ifdef DEBUG
        for (int i : p[id]) cout << i << " ";
        cout << endl;
#endif
    }
    for (int i : p[id]) {
        int tmp = 0;
        for (int j : e[i]) {
            if (flag[j]) ++tmp;
        }
    }
    for (int i = 1, u, v; i <= n; ++i) {
        u = flag[i] ? i : mini;
        for (int j : e[i]) {
            v = flag[j] ? j : mini;
            if (u == v || mp.count({u, v})) continue;
            _e[u].push_back(v);
            mp.insert({{u, v}, 1});
        }
    }
    // build tree
    int cnt = 0, res = 0;
    for (int i : p[id]) {
        for (int j : p[id]) {
            if (i == j || mp.count({i, j})) continue;
            if (dsu.connect(i, j)) ++cnt;
        }
    }
    if (cnt >= (int)p[id].size()-1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i : p[id]) {
        for (int j : _e[i]) {
            if (dsu.connect(i, j)) {
                ++res;
                if (++cnt >= (int)p[id].size()-1) {
                    cout << res << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
