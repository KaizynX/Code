/*
 * @Author: Kaizyn
 * @Date: 2020-12-31 01:41:20
 * @LastEditTime: 2020-12-31 10:26:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

struct DSU {
  int fa[N];
  void init(int n) { iota(fa, fa+n+1, 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy;
    return true;
  }
};

int n, m;
DSU dsu;
int l[N], r[N], a[N];

inline void solve() {
  cin >> n >> m;
  dsu.init(m);
  vector<int> res;
  for (int i = 1, k, x, y; i <= n; ++i) {
    cin >> k;
    if (k == 1) {
      cin >> x;
      x = dsu[x];
      if (!a[x]) {
        a[x] = 1;
        res.emplace_back(i);
      }
    } else {
      cin >> x >> y;
      x = dsu[x];
      y = dsu[y];
      if (x != y && a[x]+a[y] <= 1) {
        dsu.merge(x, y);
        a[y] += a[x];
        res.emplace_back(i);
      }
    }
  }
  cout << qpow(2, res.size()) << " " << res.size() << endl;
  for (int &i : res) cout << i << " ";
  cout << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}