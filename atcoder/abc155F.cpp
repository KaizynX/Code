#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int M = 2e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n, m;
int a[N], b[N], l[M], r[M], d[N], vis[N], use[M];
list<pii> e[N];
vector<int> des;

int dfs(const int &u)
{
    vis[u] = 1;
    for (pii v : e[u]) {
        if (!vis[v.first] && dfs(v.first)) {
            d[u] ^= 1;
            use[v.second] = 1;
        }
    }
    return d[u];
}

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    for (int i = 1; i <= m; ++i)
        cin >> l[i] >> r[i];

    des.resize(n);
    for (int i = 1; i <= n; ++i)
        des[i-1] = a[i];
    sort(des.begin(), des.end());
    // des.erase(unique(des.begin(), des.end()), des.end());
    for (int i = 1; i <= n; ++i) {
        int p = lower_bound(des.begin(), des.end(), a[i])-des.begin()+1;
        d[p] = b[i];
    }
    for (int i = n+1; i; --i)
        d[i] ^= d[i-1];
    for (int i = 1; i <= m; ++i) {
        l[i] = lower_bound(des.begin(), des.end(), l[i])-des.begin()+1;
        r[i] = upper_bound(des.begin(), des.end(), r[i])-des.begin()+1;
        if (l[i] >= r[i]) continue;
        e[l[i]].push_back({r[i], i});
        e[r[i]].push_back({l[i], i});
    }
    for (int i = 1; i <= n+1; ++i) {
        if (!vis[i] && dfs(i)) {
            cout << -1 << endl;
            return;
        }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i)
        res += use[i];
    cout << res << endl;
    for (int i = 1; i <= m; ++i)
        if (use[i]) cout << i << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}