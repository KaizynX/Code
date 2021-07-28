/*
 * @Author: Kaizyn
 * @Date: 2021-07-28 13:52:12
 * @LastEditTime: 2021-07-28 14:18:59
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
const int N = 1e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

struct Node {
  int u, v, w, c;
  bool operator <(const Node &b) const {
    return w == b.w ? c > b.c : w < b.w;
  }
};

int n, m, need, mst;
Node e[N], cp[N];
DSU dsu;

int check(int k) {
  for (int i = 1; i <= m; ++i) {
    cp[i] = e[i];
    if (cp[i].c == 0) cp[i].w += k;
  }
  sort(cp+1, cp+m+1);
  dsu.init(n);
  mst = 0;
  int x = 0;
  for (int i = 1, cnt = 0; i <= m && cnt < n-1; ++i) {
    if (dsu.merge(cp[i].u, cp[i].v)) {
      mst += cp[i].w;
      ++cnt;
      x += cp[i].c == 0;
    }
  }
  return x;
}

inline void solve() {
  cin >> n >> m >> need;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].u >> e[i].v >> e[i].w >> e[i].c;
  }
  int l = -100, r = 100;
  while (l < r) {
    int mid = (l+r)>>1;
    if (check(mid) <= need) r = mid;
    else l = mid+1;
  }
  check(l);
  cout << mst-need*l << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}