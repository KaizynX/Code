/*
 * @Author: Kaizyn
 * @Date: 2021-03-12 21:12:16
 * @LastEditTime: 2021-03-12 21:18:54
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e4+7;

struct DSU {
  vector<int> fa, rk;
  void init(int n) { fa = rk = vector<int>(n+1, 0); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : get(fa[s]); }
  int operator [](int i) { return get(i); }
  bool merge(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return false;
    if (rk[x] < rk[y]) fa[x] = y;
    else fa[y] = x, rk[x] += rk[x] == rk[y];
    return true;
  }
};

int n, m;
DSU dsu;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n >> m;
  dsu.init(n);
  for (int _ = m, q, x, y; _; --_) {
    cin >> q >> x >> y;
    if (q == 1) dsu.merge(x, y);
    else cout << (dsu[x] == dsu[y] ? "Y" : "N") << '\n';
  }
  return 0;
}