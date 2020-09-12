/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 20:32:28
 * @LastEditTime: 2020-09-09 20:51:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1<<20;

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

int n, m;
int x[N], t[N];
vector<int> b[20];
DSU dsu;

int brute() {
  int res = 0, cnt = 0;
  for (int c = 1; c <= 20; ++c) {
    for (int i = 1; i <= n; ++i) {
      for (const int &k : b[c]) {
        if (t[x[i]^k] && dsu.merge(x[i], x[i]^k)) {
          res += c;
          if (++cnt == n-1) return res;
        }
      }
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
    t[x[i]] = 1;
    m = max(m, x[i]);
  }
  dsu.init(m);
  for (int i = 1; i < 1<<20; ++i) {
    b[__builtin_popcount(i)].emplace_back(i);
  }
  cout << brute() << endl;
  return 0;
}