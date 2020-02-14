#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 1e4+7;

int n, tot;
int mmp[M];
vector<int> vec[N];
map<int, int> mp;

struct Node
{
    int i, r, t, m;
    Node(int _i = 0, int _r = 1, int _t = 0, int _m = 0) : i(_i), r(_r), t(_t), m(_m) {}
    Node operator += (const Node &node) {
        this->r += node.r;
        this->t += node.t;
        this->m += node.m;
        return *this;
    }
    friend bool operator < (const Node &n1, const Node &n2) {
        if (1ll*n1.m*n2.r == 1ll*n2.m*n1.r) return mmp[n1.i] < mmp[n2.i];
        return 1ll*n1.m*n2.r > 1ll*n2.m*n1.r;
    }
} v[M];
vector<Node> res;

struct DSU
{
    int fa[M];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    void merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return;
        if (mmp[fx] < mmp[fy]) {
            v[fx] += v[fy];
            v[fy] = Node(v[fy].i);
            fa[fy] = fx;
        } else {
            v[fy] += v[fx];
            v[fx] = Node(v[fx].i);
            fa[fx] = fy;
        }
    }
} dsu;

inline int id(int x)
{
    if (mp.count(x)) return mp[x];
    else {
        ++tot;
        v[tot].i = tot;
        mmp[tot] = x;
        return mp[x] = tot;
    }
}

int main()
{
    scanf("%d", &n);
    dsu.init(10000);
    for (int i = 1, a, k; i <= n; ++i) {
        scanf("%d", &a); if (a != -1) vec[i].emplace_back(id(a));
        scanf("%d", &a); if (a != -1) vec[i].emplace_back(id(a));
        scanf("%d", &a); if (a != -1) vec[i].emplace_back(id(a));
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a); if (a != -1) vec[i].emplace_back(id(a));
        }
        scanf("%d", &a); v[vec[i].front()].t += a;
        scanf("%d", &a); v[vec[i].front()].m += a;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : vec[i])
            dsu.merge(vec[i].front(), j);
    }
    for (int i = 1; i <= tot; ++i)
        if (dsu[i] == i) res.emplace_back(v[i]);
    printf("%d\n", res.size());
    sort(res.begin(), res.end());
    for (Node u : res) {
        printf("%04d %d %.3f %.3f\n", mmp[u.i], u.r, 1.0*u.t/u.r, 1.0*u.m/u.r);
    }
    return 0;
}
