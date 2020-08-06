/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 18:13:34
 * @LastEditTime: 2020-07-19 19:02:47
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

int n, m;
int a[N], b[N], rk[N];
long long sum[N];
priority_queue<pii> q;

inline void solve() {
  cin >> m >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    rk[i] = i;
  }

  long long res = 0;
  sort(rk+1, rk+n+1, [&](const int &x, const int &y) {
    return a[x] > a[y];
  });
  for (int i = 1; i <= min(n, m); ++i) res += a[i];
  sort(rk+1, rk+n+1, [&](const int &x, const int &y) {
    return b[x] == b[y] ? a[x] > a[y] : b[x] > b[y];
  });
  res = max(res, a[rk[1]]+(m-1ll)*b[rk[1]]);
  for (int i = 2; i <= n; ++i) q.push({a[rk[i]], rk[i]});
  int r = m-1;
  while (r && q.top().first > b[rk[1]]) {
    pii u = q.top();
    q.pop();
    res -= b[rk[1]];
    res += u.first;
    --r;
    q.push({b[u.second], u.second});
  }
  if (!r && q.top().first > a[rk[1]]) {
    res -= a[rk[1]];
    res += q.top().first;
  }
  /*
  for (int i = 2, r = m-1; i <= n && r >= 0; ++i) {
    if (r && a[rk[i]] > b[rk[1]]) {
      --r;
      res -= b[rk[1]];
      res += a[rk[i]];
    } else if (!r && a[rk[i]] > a[rk[1]]) {
      --r;
      res -= a[rk[1]];
      res += a[rk[i]];
    }
  }
  */
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