/*
 * @Author: Kaizyn
 * @Date: 2020-12-31 00:40:12
 * @LastEditTime: 2020-12-31 01:13:33
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
    if (fx > fy) swap(fx, fy);
    fa[fx] = fy;
    return true;
  }
};

int n, m;
DSU dsu;
int l[N], r[N], a[N];

bool work(int x, int i) {
  if (a[x]) return false;
  else return a[x] = i;
}

inline void solve() {
  cin >> n >> m;
  dsu.init(m);
  // memset(a+1, 0, sizeof(int)*m);
  for (int i = 1, k, x, y; i <= n; ++i) {
    cin >> k;
    if (k == 1) {
      cin >> x;
      if (!work(x, i)) work(dsu[x], i);
    } else {
      cin >> x >> y;
      if (x > y) swap(x, y);
      if (!work(x, i) && dsu[x] != dsu[y]) {
        if (dsu[x] == x) work(y, i);
        else work(min(y, dsu[x]), i);
      }
      dsu.merge(x, y);
    }
  }
  vector<int> res;
  for (int i = 1; i <= m; ++i) {
    if (a[i]) res.emplace_back(a[i]);
  }
  sort(res.begin(), res.end());
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
/*
n m
1 1 1
2 1 2
2 1 3
2 1 4
2 1 5
...
*/