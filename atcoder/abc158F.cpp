/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 10:56:21
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 11:05:04
 * @FilePath: \Code\atcoder\abc158F.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct DSU
{
    int fa[N], num[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
        else num[fy] += num[fx], fa[fx] = fy;
        return true;
    }
} dsu;

struct Node
{
    int x, d;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.x < n2.x;
    }
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.d;
    }
} a[N];

int n;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    dsu.init(n);
    for (int i = n-1; i; --i) {
        if (a[i+1].x < a[i].x+a[i].d) {
            dsu.merge(i, i+1);
        }
    }
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] == i) {
            res = res*(dsu.num[i]+1)%MOD;
        }
    }
    cout << res << endl;
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