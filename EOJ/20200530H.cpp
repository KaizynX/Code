/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 13:03:47
 * @LastEditTime: 2020-05-30 13:16:00
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
const int K = 3e5+7;

struct Node {
  char op;
  int v;
  long long t;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.t > rhs.t;
  }
  friend istream& operator >>(istream &is, Node &nd) {
    return is >> nd.op >> nd.v >> nd.t;
  }
};

int n, m, k;
long long a[N][N];
Node q[K];

inline void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) { 
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      a[i][j] %= MOD;
    }
  }
  for (int i = 1; i <= k; ++i) {
    cin >> q[i];
  }
  sort(q+1, q+k+1);
  long long res = 0;
  for (int i = 1; i <= k; ++i) {
    long long sum = 0;
    if (q[i].op == 'r') {
      for (int j = 1; j <= m; ++j) {
        sum += a[q[i].v][j];
        a[q[i].v][j] = 0;
      }
    } else {
      for (int j = 1; j <= n; ++j) {
        sum += a[j][q[i].v];
        a[j][q[i].v] = 0;
      }
    }
    sum %= MOD;
    (res += q[i].t%MOD*sum) %= MOD;
  }
  cout << res << endl;
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