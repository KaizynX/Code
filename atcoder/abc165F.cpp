/*
 * @Author: Kaizyn
 * @Date: 2020-05-03 10:18:30
 * @LastEditTime: 2020-05-03 11:12:26
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N], res[N];
vector<int> e[N];
vector<int> lis[N];

void dfs(const int &u, const int &fa) {
    int p, len = m;
    if (a[u] > lis[m].back()) {
        lis[++m].emplace_back(a[u]);
        p = m;
    } else {
        int l = 1, r = m;
        while (l < r) {
            int mid = (l+r)>>1;
            if (lis[mid].back() >= a[u]) r = mid;
            else l = mid+1;
        }
        lis[l].emplace_back(a[u]);
        p = l;
    }
    res[u] = m;
    for (const int &v : e[u]) if (v != fa) {
        dfs(v, u);
    }
    lis[p].pop_back();
    m = len;
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    lis[0].emplace_back(0);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << res[i] << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}