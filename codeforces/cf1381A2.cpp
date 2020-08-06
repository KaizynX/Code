/*
 * @Author: Kaizyn
 * @Date: 2020-07-21 22:16:31
 * @LastEditTime: 2020-07-21 23:07:45
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
  void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
string s;
int a[N], b[N];
vector<int> res;
BinaryIndexedTree<int> bit;

inline int get_val(const int &x) {
  return a[x]^(bit.query(x)&1);
}

inline void solve() {
  cin >> n;
  cin >> s;
  for (int i = 1; i <= n; ++i) a[i] = s[i-1]-'0';
  cin >> s;
  for (int i = 1; i <= n; ++i) b[i] = s[i-1]-'0';

  /*
  for (int i = n; i > 1; --i) {
    if (a[i] == b[i]) continue;
    if (a[1] == a[i]) {
      res.emplace_back(i);
      rev(i);
    } else {
      res.emplace_back(1);
      a[0] ^= 1;
      res.emplace_back(i);
      rev(i);
    }
  }
  */
  res.clear();
  bit.init(n);
  int l = 1, r = n, rev = 0;
  for (int i = n; i > 1; --i) {
    if (!rev) {
      if (b[i] == get_val(r)) {
        --r;
        continue;
      }
      if (get_val(l) != get_val(r)) {
        res.emplace_back(1);
        // bit.add(l, 1);
      }
      res.emplace_back(i);
      bit.add(l, r, 1);
      rev ^= 1;
      ++l;
      // --r;
    } else {
      if (b[i] == get_val(l)) {
        ++l;
        continue;
      }
      if (get_val(l) != get_val(r)) {
        res.emplace_back(1);
        // bit.add(r, 1);
      }
      res.emplace_back(i);
      bit.add(l, r, 1);
      rev ^= 1;
      --r;
      // ++l;
    }
  }
  if (get_val(l) != b[1]) res.emplace_back(1);
  cout << res.size();
  for (const int &i : res) cout << " " << i;
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}