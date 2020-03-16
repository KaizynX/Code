/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 16:19:05
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 16:29:56
 * @FilePath: \Code\pintia\2020031504.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int M = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

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

int n, a, b, q;
int x[N], y[N], h[N];
char res[N];

inline void solve()
{
    cin >> n >> a >> b >> q;
    dsu.init(n);
    memset(res, '?', sizeof res);
    for (int i = 1; i <= a; ++i) {
        cin >> x[i];
        cin >> res[x[i]];
    }
    for (int i = 1; i <= b; ++i) {
        cin >> y[i] >> h[i];
    }
    y[b+1] = n+1;
    for (int i = 1; i <= b; ++i) {
        if (!h[i]) continue;
        for (int j = 0; y[i]+j < y[i+1]; ++j) {
            dsu.merge(y[i]+j, h[i]+j);
        }
    }
    for (int i = 1; i <= a; ++i) {
        res[dsu[x[i]]] = res[x[i]];
    }
    for (int i = 1, z; i <= q; ++i) {
        cin >> z;
        cout << res[dsu[z]];
    }
    cout << endl;
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