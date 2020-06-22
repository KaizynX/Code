/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 14:17:49
 * @LastEditTime: 2020-06-13 14:42:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;
const int M = 15;

struct DSU {
  int fa[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};

struct Node {
  int x, y;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.x == rhs.x ? lhs.y < rhs.y : lhs.x < rhs.x;
  }
  friend bool operator ==(const Node &lhs, const Node &rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
  }
};

int n;
int check[1<<M], sg[1<<M], vis[N];
Node a[N];
DSU dsu;

inline void solve() {
  cin >> n;
  dsu.init(n);
  for (int i = 0, g; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    if (a[i].x == 0 && a[i].y == 0) {
      continue;
    } else if (a[i].x == 0) {
      a[i].y = 1;
    } else if (a[i].y == 0) {
      a[i].x = 1;
    } else {
      g = __gcd(abs(a[i].x), abs(a[i].y));
      a[i].x /= g; a[i].y /= g;
      if (a[i].x < 0) a[i].x = -a[i].x, a[i].y = -a[i].y;
    }
  }
  sort(a, a+n);
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[i-1]) dsu.merge(i, i-1);
  }
  // check[0] = 0;
  for (int i = 1, cnt, kind; i < 1<<n; ++i) {
    cnt = kind = 0;
    for (int j = 0; j < n; ++j) if ((i>>j)&1) {
      ++cnt;
      if (!vis[dsu[j]]) ++kind, vis[dsu[j]] = 1;
    }
    if (cnt <= 2 || kind <= 1) check[i] = 1;
  }
  sg[0] = 0;
  for (int i = 1; i < 1<<n; ++i) {
    if (check[i]) sg[i] = 1;
    for (int j = i; j; j = (j-1)&i) if (check[i^j]) {
      sg[i] |= sg[j]^1;
    }
  }
  cout << (sg[(1<<n)-1] ? "zyh" : "fzj") << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}