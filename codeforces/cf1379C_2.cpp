/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 18:13:34
 * @LastEditTime: 2020-07-19 23:53:44
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

struct Node {
  int a, b;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.a < rhs.a;
  }
};

int n, m;
Node c[N];
long long sum[N];

inline void solve() {
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> c[i].a >> c[i].b;
  }

  sort(c+1, c+n+1);
  sum[n+1] = 0;
  for (int i = n; i; --i) sum[i] = sum[i+1]+c[i].a;
  long long res = sum[max(1, n-m+1)];
  for (int i = 1; i <= n; ++i) {
    int p = upper_bound(c+1, c+n+1, Node{c[i].b, 0})-c;
    int cnt = min(n-p+1, m-1);
    long long cur = sum[n-cnt+1]+(m-cnt-1ll)*c[i].b;
    if (cnt > 0 && c[i].a >= c[n-cnt+1].a) {
      if (cnt < n) {
        cur += max(c[i].b, c[n-cnt].a);
      } else {
        cur += c[i].b;
      }
    } else {
      cur += c[i].a;
    }
    // cout << c[i].a << " " << p << " " << cnt << " " << val << " " << cur << endl;
    res = max(res, cur);
  }
  cout << res << endl;
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