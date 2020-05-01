/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 20:33:08
 * @LastEditTime: 2020-05-01 10:47:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int v[N], num[N], son[N], cnt[N], res[N];
vector<int> e[N], fac[N], tr[N];

inline void factor(const int &i) {
    for (int x = 1; x*x <= v[i]; ++x) {
        if (v[i]%x) continue;
        fac[i].emplace_back(x);
        if (v[i]/x != x) fac[i].emplace_back(v[i]/x);
    }
    sort(fac[i].begin(), fac[i].end());
}

void get_son(const int &u) {
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) {
        get_son(v);
        num[u] += num[v];
        if (num[v] > num[son[u]]) son[u] = v;
    }
}

void my_merge(const int &id, const vector<int> &v) {
    vector<int> vec;
    vector<int> &u = tr[id];
    int i = 0, j = 0;
    while (i < (int)u.size() && j < (int)v.size()) {
        if (u[i] < v[j]) vec.emplace_back(u[i++]);
        else if (u[i] > v[j]) vec.emplace_back(v[j++]);
        else {
            vec.emplace_back(u[i]);
            res[id] = max(res[id], u[i]);
            ++i; ++j;
        }
    }
    vec.insert(vec.end(), u.begin()+i, u.end());
    vec.insert(vec.end(), v.begin()+j, v.end());
    swap(vec, u);
}

void dfs(const int &u) {
    for (const int &v : e[u]) if (v != son[u]) dfs(v);
    if (son[u]) dfs(son[u]), swap(tr[u], tr[son[u]]);
    res[u] = -1;
    for (const int &v : e[u]) if (v != son[u]) my_merge(u, tr[v]);
    my_merge(u, fac[u]);
}

inline void solve()
{
    for (int i = 1; i <= n; ++i) {
        vector<int>().swap(e[i]);
        vector<int>().swap(fac[i]);
        vector<int>().swap(tr[i]);
    }
    for (int i = 2, x; i <= n; ++i) {
        scanf("%d", &x);
        e[x].emplace_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", v+i);
        factor(i);
    }
    get_son(1);
    dfs(1);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", res[i]);
    }
}

signed main()
{
    while (scanf("%d", &n) == 1) solve();
    return 0;
}