/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 22:17:55
 * @LastEditTime: 2020-03-31 22:22:30
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

int n, k;
int cnt[N][30];
string s;

inline void solve()
{
    cin >> n >> k >> s;
    dsu.init(n);
    for (int i = 1; i+k <= n; ++i) dsu.merge(i, i+k);
    for (int i = 1; n+1-i > i; ++i) dsu.merge(i, n+1-i);
    for (int i = 1; i <= n; ++i)
        if (dsu[i] == i) memset(cnt[i], 0, sizeof cnt[i]);
    for (int i = 1; i <= n; ++i) {
        ++cnt[dsu[i]][s[i-1]-'a'];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] == i) {
            int mx = 0;
            for (int j = 0; j < 26; ++j) mx = max(mx, cnt[i][j]);
            res += dsu.num[i]-mx;
        }
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}