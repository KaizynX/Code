#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m;
int flag[N];
vector<int> e[N], p, del;
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

#ifdef DEBUG
inline void print(vector<int> &v) {
    for (int i : v) cout << i << " ";
    cout << endl;
}
#endif

int main()
{
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        mp.insert({{a, b}, 1});
        mp.insert({{b, a}, 1});
    }
    // rebuild map
    int mini = 1;
    for (int i = 2; i <= n; ++i) {
        if (e[i].size() < e[mini].size())
            mini = i;
    }
    // del the first point
    p.emplace_back(mini);
    flag[mini] = 1;
    for (int i : e[mini]) {
        p.emplace_back(i);
        flag[i] = 1;
    }
#ifdef DEBUG
    print(p);
#endif
    // second del point
    int del_num = n-p.size();
    for (auto it = p.begin(); it != p.end(); ++it) {
        if (*it == mini) continue;
        int tmp = 0;
        for (int j : e[*it]) {
            if (!flag[j])
                ++tmp;
        }
        if (tmp == del_num) continue;
        del.emplace_back(*it);
        --it;
        p.erase(it+1);
    }
#ifdef DEBUG
    print(p);
#endif
    // third del pointk
    for (auto i = del.begin(); i != del.end(); ++i) {
        flag[*i] = 0;
        for (auto j = p.begin(); j != p.end(); ++j) {
            if (*j == mini) continue;
            if (mp.count({*i, *j})) continue;
            del.emplace_back(*j);
            --j;
            p.erase(j+1);
        }
    }
#ifdef DEBUG
    print(p);
#endif
    // build tree
    int cnt = 0, res = 0;
    for (int i : p) {
        for (int j : p) {
            if (i == j || mp.count({i, j})) continue;
            if (dsu.connect(i, j)) ++cnt;
        }
    }
    if (cnt >= (int)p.size()-1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i : p) {
        for (int j : p) {
            if (i == j || !mp.count({i, j})) continue;
            if (dsu.connect(i, j)) {
                ++res;
                if (++cnt >= (int)p.size()-1) {
                    cout << res << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}
