/*
 * @Author: Kaizyn
 * @Date: 2020-04-23 22:08:56
 * @LastEditTime: 2020-04-23 23:13:11
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

struct DSU
{
    int fa[N], num[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        if (fx >= fy) num[fx] += num[fy], fa[fy] = fx;
        else num[fy] += num[fx], fa[fx] = fy;
        return true;
    }
} dsu;

int n;
int a[N], p[N], t[N];
multiset<int> mxt;
DSU r;

inline bool solve()
{
    cin >> n;
    r.init(n+1);
    mxt.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
        mxt.insert(1);
    }
    for (int i = 1; i <= n; ++i) {
        // get maxcount
        int cur = *mxt.rbegin();
        if (cur != r.num[r[p[i]]] || r[p[i]] != p[i]) return false;
        mxt.erase(mxt.end()-1);
        mxt.insert(t[p[i]]);
        r.merge(p[i], p[i]+1);
        if (r[p[i]] > n) continue;
        mxt.erase(mxt.find(t[r[p[i]]]));
        ++t[r[p[i]]];
        mxt.insert(t[r[p[i]]]);
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}