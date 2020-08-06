/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 13:51:08
 * @LastEditTime: 2020-07-17 15:50:51
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;
const int M = 5e1+7;

struct Func {
  int k, b;
  Func() {}
  Func(const int &_k, const int &_b) : k(_k), b(_b) {}
  long long operator ()(const int &x) const {
    return k*x+b;
  }
};

struct CrossPoint {
  int x;
  int i, j;
  CrossPoint() {}
  CrossPoint(const int &_x, const int &_i, const int &_j) : x(_x), i(_i), j(_j) {}
  friend bool operator <(const CrossPoint &lhs, const CrossPoint &rhs) {
    return lhs.x < rhs.s;
  }
};

int n, m;
int a[N][M], b[N*M], rk[N], res[N];
Func f[N];
set<CrossPoint> cp;

CrossPoint cross(const int &i, const int &j) {
  if (f[i].k == f[j].k) return CrossPoint(0, i, j);
  return CrossPoint((int)ceil(1.0*(f[j].b-f[i].b)/(f[i].k-f[j].k)), i, j);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      b[(i-1)*m+j] = a[i][j];
    }
    res[i] = n;
    f[i] = Func(m, 0);
    sort(a[i]+1, a[i]+m+1);
  }
  sort(b+1, b+n*m+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) if (i != j) {
      cp.insert(cross(i, j));
    }
  }
  for (int i = 1; i <= p; ++i) {
    // (b[i-1], b[i]]
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