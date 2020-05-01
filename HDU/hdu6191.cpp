/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 10:34:08
 * @LastEditTime: 2020-04-30 14:00:20
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

template <class T>
struct PreSumLB
{
    int tot, sz = sizeof(T)*8;
    vector<T> b[N];
    vector<int> p[N];
    PreSumLB() { init(); }
    void init() {
        tot = 0;
        vector<T>(sz, 0).swap(b[0]);
        vector<int>(sz, 0).swap(p[0]);
    }
    void append(T val) {
        int pos = ++tot;
        vector<T> &bb = b[tot];
        vector<int> &pp = p[tot];
        pp = p[tot-1];
        bb = b[tot-1];
        for (int i = sz-1; i >= 0; --i) if ((val>>i)&1) {
            if (bb[i]) {
                if (pos > pp[i]) swap(pos, pp[i]), swap(val, bb[i]);
                val ^= bb[i];
            } else {
                bb[i] = val;
                pp[i] = pos;
                return;
            }
        }
    }
    T query(const int &l, const int &r, T res = 0) {
        vector<T> &bb = b[r];
        vector<int> &pp = p[r];
        for (int i = sz-1; i >= 0; --i)
            if (pp[i] >= l) res = max(res, res^bb[i]);
        return res;
    }
};

int n, q, dfn;
int v[N], st[N], ed[N], a[N];
vector<int> e[N];
PreSumLB<int> presum;

void dfs(const int &u) {
    st[u] = ++dfn;
    for (const int &v : e[u]) dfs(v);
    ed[u] = dfn;
}

inline void solve()
{
    dfn = 0;
    presum.init();
    for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 2, f; i <= n; ++i) {
        cin >> f;
        e[f].emplace_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) a[st[i]] = v[i];
    for (int i = 1; i <= n; ++i) presum.append(a[i]);
    for (int i = 1, u, x; i <= q; ++i) {
        cin >> u >> x;
        cout << presum.query(st[u], ed[u], x) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> q) solve();
    return 0;
}