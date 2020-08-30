/*
 * @Author: Kaizyn
 * @Date: 2020-08-27 12:43:42
 * @LastEditTime: 2020-08-27 13:04:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, q;
int c[N], res[N];
vector<int> col[N];
vector<pii> qqq[N];
BinaryIndexedTree<int> bit;

inline void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i];
    col[c[i]].emplace_back(i);
  }
  for (int i = 1, l, r; i <= q; ++i) {
    cin >> l >> r;
    qqq[l].emplace_back(r, i);
  }
  bit.init(n);
  for (int i = 1; i <= n; ++i) if (col[i].size()) {
    bit.add(col[i].front(), 1);
    reverse(col[i].begin(), col[i].end());
  }
  for (int i = 1; i <= n; ++i) {
    for (auto &qq : qqq[i]) {
      res[qq.second] = bit.query(qq.first);
    }
    bit.add(i, -1);
    col[c[i]].pop_back();
    if (col[c[i]].size()) bit.add(col[c[i]].back(), 1);
  }
  for (int i = 1; i <= q; ++i) {
    cout << res[i] << endl;
  }
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