/*
 * @Author: Kaizyn
 * @Date: 2020-06-16 22:33:48
 * @LastEditTime: 2020-06-19 11:01:28
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

int n;
int a[N], b[N];
int fir[N], p[N], dp[N], mv[N], occ[N];

void discrete() {
  static int m;
  static int d[N];
  memcpy(d+1, a+1, sizeof(int)*n);
  sort(d+1, d+n+1);
  m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(d+1, d+m, a[i])-d;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  discrete();
  memset(p+1, 0, sizeof(int)*n);
  memset(dp+1, 0, sizeof(int)*n);
  memset(mv+1, 0, sizeof(int)*n);
  memset(occ+1, 0, sizeof(int)*n);
  memcpy(b+1, a+1, sizeof(int)*n);
  sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
    if (p[b[i]] == 0) {
      p[b[i]] = fir[b[i]] = i;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[p[a[i]]] = max(dp[p[a[i]]-1], occ[a[i]-1])+1;
    mv[a[i]] = max(dp[p[a[i]]], dp[fir[a[i]]-1])+1;
    res = max({res, dp[p[a[i]]], mv[a[i]]});
    ++p[a[i]];
    ++occ[a[i]];
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