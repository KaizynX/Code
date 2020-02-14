#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m, tot;
int sex[N], d[N], f[N][20], lg2[N];
string mmp[N];
map<string, int> mp;
vector<int> e[N], root;

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

void build_tree(int u, int fa, int rt)
{
    dsu.merge(u, rt);
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for(int i = 1; (1<<i) <= d[u]; ++i)
        f[u][i] = f[f[u][i-1]][i-1];
    for (int v : e[u]) {
        build_tree(v, u, rt);
    }
}

int lca(int x, int y)
{
    if(d[x] < d[y]) swap(x, y);
    while(d[x] > d[y])
        x = f[x][lg2[d[x]-d[y]]-1];
    if(x == y) return x;
    for(int i = lg2[d[x]]; i >= 0; --i)
        if(f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    return f[x][0];
}

inline int get_id(const string &x)
{
    if (mp.count(x)) return mp[x];
    mmp[++tot] = x;
    return mp[x] = tot;
}

int main()
{
    string s1, s2, s3, s4;
    cin >> n;
    for (int i = 1, x; i <= n; ++i) {
        cin >> s1 >> s2;
        x = get_id(s1);
        if (s2.length() > 4 && s2.substr(s2.length()-4, 4) == "sson") {
            sex[x] = 0;
            e[get_id(s2.substr(0, s2.length()-4))].emplace_back(x);
        } else if (s2.length() > 7 && s2.substr(s2.length()-7, 7) == "sdottir") {
            sex[x] = 1;
            e[get_id(s2.substr(0, s2.length()-7))].emplace_back(x);
        } else {
            sex[x] = s2.back() == 'f';
            root.emplace_back(x);
        }
    }
    dsu.init(tot);
    for (int i = 1; i <= tot; ++i) lg2[i] = lg2[i>>1]+1;
    for (int i : root) build_tree(i, 0, i);
    cin >> m;
    for (int i = 1, x, y, rt; i <= m; ++i) {
        cin >> s1 >> s2 >> s3 >> s4;
        if (!mp.count(s1) || !mp.count(s3)) { cout << "NA" << endl; continue; }
        x = mp[s1]; y = mp[s3];
        if (sex[x] == sex[y]) {
            cout << "Whatever" << endl;
            continue;
        }
        if (dsu[x] != dsu[y]) { cout << "Yes" << endl; continue; }
        rt = lca(x, y);
        cout << (d[x]-d[rt] > 3 && d[y]-d[rt] > 3 ? "Yes" : "No") << endl;
    }
    return 0;
}
