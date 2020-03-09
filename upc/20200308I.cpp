/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 19:30:48
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 20:07:59
 * @FilePath: \Code\upc\20200308I.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
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

int n, m;

struct Node
{
    int x, y, z, v;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.y >> nd.z >> nd.v;
    }
    friend bool check(const Node &n1, const Node &n2) {
        long long dis = 1ll*abs(n1.x-n2.x)+abs(n1.y-n2.y)+abs(n1.z-n2.z);
        return dis <= 1 && abs(n1.v-n2.v) <= m;
    }
} a[N];

inline void solve()
{
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        for (int j = 1; j < i; ++j) {
            if (check(a[i], a[j])) dsu.merge(i, j);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] == i) ++res;
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