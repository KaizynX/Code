/*
 * @Author: Kaizyn
 * @Date: 2020-06-16 22:33:48
 * @LastEditTime: 2020-06-17 23:31:46
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

struct Node {
  int v, p;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.v == rhs.v ? lhs.p < rhs.p : lhs.v < rhs.v;
  }
};

int n;
int a[N];
int dp[N];

void discrete() {
  static Node d[N];
  for (int i = 1; i <= n; ++i) d[i] = {a[i], i};
  sort(d+1, d+n+1);
  for (int i = 1; i <= n; ++i) {
    a[d[i].p] = i;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  discrete();
  memset(dp+1, 0, sizeof(int)*n);
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i==n];
  }
#endif
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[a[i]] = dp[a[i]-1]+1;
    res = max(res, dp[a[i]]);
  }
  cout << n-res << endl;
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