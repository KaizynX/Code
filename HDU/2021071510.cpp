/*
 * @Author: Kaizyn
 * @Date: 2021-07-15 13:00:30
 * @LastEditTime: 2021-07-15 13:10:53
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

struct Euler {
  vector<int> prime;
  vector<bool> check;
  bool operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<bool>(n+1, true);
    check[1] = false;
    for (int i = 2; i <= n; ++i) {
      if (check[i]) prime.emplace_back(i);
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = false;
        if (i%j == 0) break;
      }
    }
  }
} E;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int a, P;
int b[N];
BinaryIndexedTree<int> tree;

int rev() {
  tree.init(P);
  int res = 0;
  for (int i = P-1; i; --i) {
    res ^= tree.query(b[i])&1;
    tree.add(b[i], 1);
  }
  return res;
}

inline void solve() {
  E.init(N);
  for (int p : E.prime) {
    P = p;
    if (p == 2) continue;
    for (a = 1; a < P; ++a) {
      for (int i = 1; i < P; ++i) b[i] = a*i%P+1;
      int res = rev();
      cout << a << ' ' << P << ' ' << res << '\n';
    }
    cout << "***\n";
  }
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