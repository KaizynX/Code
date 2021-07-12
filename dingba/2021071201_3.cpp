/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 15:22:56
 * @LastEditTime: 2021-07-12 15:35:48
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

template <typename T>
struct BIT_2D {
  int n, m;
  unordered_map<int, unordered_map<int, T>> a, tr;
  void init(const int &_n, const int &_m) {
    n = _n; m = _m;
    a.clear();
    tr.clear();
  }
  void add(const int &x, const int &y, const T &k) {
    a[x][y] += k;
    for (int i = x; i <= n; i += i&-i)
      for (int j = y; j <= m; j += j&-j)
        tr[i][j] += k;
  }
  T query(const int &x, const int &y) {
    return a[x][y];
    // return query(x, y, x, y);
  }
  T query(int r1, int c1, int r2, int c2) {
    if (r1 > r2) swap(r1, r2);
    if (c1 > c2) swap(c1, c2);
    return _query(r2, c2)-_query(r1-1, c2)-_query(r2, c1-1)+_query(r1-1, c1-1);
  }
  T _query(const int &x, const int &y) {
    T res = 0;
    for (int i = x; i; i -= i&-i)
      for (int j = y; j; j -= j&-j)
        res += tr[i][j];
    return res;
  }
};

struct Node {
  int x[3], id;
  bool operator <(const Node &b) const {
    return x[0] < b.x[0];
    // return vector<int>{x, y, z} < vector<int>{b.x, b.y, b.z};
  }
};

int n, d[3];
int X[3][N], xn[3];
Node a[N];
BIT_2D<int> tree;

int lb(int k, int x) { // first >= x
  return lower_bound(X[k]+1, X[k]+xn[k], x)-X[k];
}

int rb(int k, int x) { // last <= x
  return upper_bound(X[k]+1, X[k]+xn[k], x)-X[k]-1;
}

void discrete() {
  for (int i = 0; i < 3; ++i) {
    // X[n+1] = -2e9;
    // X[n+2] = 2e9;
    sort(X[i]+1, X[i]+n+1);
    xn[i] = unique(X[i]+1, X[i]+n+1)-X[i];
    // for (int i = 1; i <= n; ++i) a[i].x[k] = lb(k, a[i].x[k]);
  }
}

void fuck1() {
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      int flag = 1;
      for (int k = 0; k < 3; ++k) {
        flag &= abs(a[i].x[k]-a[j].x[k]) <= d[k];
      }
      if (flag) {
        res = i;
        break;
      }
    }
    if (res) break;
  }
  cout << res << '\n';
}

void fuck2() {
  set<int> st;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    auto it = st.lower_bound(a[i].x[0]-d[0]);
    if (it != st.end() && *it <= a[i].x[0]+d[0]) {
      res = i;
      break;
    }
    st.insert(a[i].x[0]);
  }
  cout << res << '\n';
}

void fuck3() {
  tree.init(n, n);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (tree.query(a[i].x[0]-d[0], a[i].x[1]-d[1], a[i].x[0]+d[0], a[i].x[1]+d[1])) {
      res = i;
      break;
    }
    tree.add(a[i].x[0], a[i].x[1], 1);
  }
  cout << res << '\n';
}

void fuck4() {
  cout << "0\n";
}

inline void solve() {
  cin >> n;
  int fy = 1, fz = 1;
  for (int i = 0; i < 3; ++i) cin >> d[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> X[j][i];
      a[i].x[j] = X[j][i];
    }
    fy &= a[i].x[1] == 1;
    fz &= a[i].x[2] == 1;
    a[i].id = i;
  }
  discrete();
  if (n <= 1000) fuck1();
  else if (fy && fz) fuck2();
  else if (fz) fuck3();
  else fuck4();
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