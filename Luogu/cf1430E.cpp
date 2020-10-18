/*
 * @Author: Kaizyn
 * @Date: 2020-10-11 17:35:59
 * @LastEditTime: 2020-10-11 17:40:15
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

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

int n;
string s, rs;
queue<int> q[26];
int a[N];
BinaryIndexedTree<int> tree;

long long calc() {
  tree.init(n);
  long long res = 0;
  for (int i = n; i; --i) {
    res += tree.query(a[i]);
    tree.add(a[i], 1);
  }
  return res;
}

inline void solve() {
  cin >> n >> s;
  for (int i = 1; i <= n; ++i) {
    q[s[i-1]-'a'].push(i);
  }
  rs = s;
  reverse(rs.begin(), rs.end());
  for (int i = 1; i <= n; ++i) {
    int c = rs[i-1]-'a';
    a[q[c].front()] = i;
    q[c].pop();
  }
  cout << calc() << endl;
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