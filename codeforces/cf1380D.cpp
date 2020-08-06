/*
 * @Author: Kaizyn
 * @Date: 2020-07-12 22:34:55
 * @LastEditTime: 2020-07-12 23:17:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
// const int INF = 0x3f3f3f3f;
const long long INF = 1e18;
const int N = 2e5+7;

int n, m, k;
long long x, y;
int a[N], b[N], p[N];

inline long long solve() {
  cin >> n >> m >> x >> k >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    // p[b[0]] = 0
    if (p[b[i]] == 0 || p[b[i]] < p[b[i-1]]) return -1;
  }
  long long res = 0;
  b[0] = b[m+1] = 0;
  for (int i = 0, l, r; i <= m; ++i) {
    l = i == 0 ? 0 : p[b[i]];
    r = i == m ? n+1 : p[b[i+1]];
    if (l+1 == r) continue;
    int mv = 0, len = r-l-1;
    for (int j = l+1; j < r; ++j) mv = max(mv, a[j]);
    long long cur = INF;
    if (mv < max(b[i], b[i+1])) {
      for (int j = 0; j*k <= len; ++j) {
        cur = min(cur, j*x+(len-j*k)*y);
      }
    } else {
      if (len < k) return -1;
      for (int j = 1; j*k <= len; ++j) {
        cur = min(cur, j*x+(len-j*k)*y);
      }
    }
    res += cur;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}