/*
 * @Author: Kaizyn
 * @Date: 2020-04-29 18:08:59
 * @LastEditTime: 2020-04-30 10:29:42
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

int n, k, q;
int w[N], res[N], cnt[N], num[N], son[N];
vector<int> e[N];

inline void disc() {
    static int m, d[N];
    memcpy(d+1, w+1, sizeof(int)*n);
    sort(d+1, d+n+1);
    m = unique(d+1, d+n+1)-d;
    for (int i = 1; i <= n; ++i) {
        w[i] = lower_bound(d+1, d+m, w[i])-d;
    }
}

void get_son(const int &u, const int &fa) {
    num[u] = 1;
    son[u] = 0;
    for (int &v : e[u]) if (v != fa) {
        get_son(v, u);
        num[u] += num[v];
        if (num[v] > num[son[u]]) son[u] = v;
    }
}

void dfs1(const int &u, const int &fa, const int &dif, const int &rt) {
    if (dif == 1 && cnt[w[u]] == k) --res[rt];
    cnt[w[u]] += dif;
    if (dif == 1 && cnt[w[u]] == k) ++res[rt];
    for (int &v : e[u]) if (v != fa) {
        dfs1(v, u, dif, rt);
    }
}

void dfs(const int &u, const int &fa, const int &keep) {
    for (int &v : e[u]) if (v != fa && v != son[u]) dfs(v, u, 0);
    if (son[u]) dfs(son[u], u, 1), res[u] = res[son[u]];
    else res[u] = 0;
    for (int &v : e[u]) if (v != fa && v != son[u]) dfs1(v, u, 1, u);
    if (cnt[w[u]] == k) --res[u];
    ++cnt[w[u]];
    if (cnt[w[u]] == k) ++res[u];
    if (!keep) {
        --cnt[w[u]];
        for (int &v : e[u]) if (v != fa) dfs1(v, u, -1, u);
    }
}

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
    memset(cnt+1, 0, sizeof(int)*n);
    memset(res+1, 0, sizeof(int)*n);
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    disc();
    get_son(1, 0);
    dfs(1, 0, 0);
    cin >> q;
    int x;
    while (q--) {
        cin >> x;
        cout << res[x] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ":\n";
        solve();
        if (i < testcase) cout << endl;
    }
    return 0;
}