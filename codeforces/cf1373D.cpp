/*
 * @Author: Kaizyn
 * @Date: 2020-06-25 22:37:34
 * @LastEditTime: 2020-06-25 22:50:54
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 2e5+7;

int n;
int a[N];
long long sum[2][N], mv[2][N];

inline void solve() {
  cin >> n;
  mv[1][0] = -INF;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum[i&1][i] = sum[i&1][i-1]+a[i];
    sum[~i&1][i] = sum[~i&1][i-1];
    mv[i&1][i] = max(mv[i&1][i-1], sum[1][i]-sum[0][i]);
    mv[~i&1][i] = mv[~i&1][i-1];
  }
  long long base = sum[1][n], res = base;
  for (int i = 2; i <= n; ++i) {
    res = max(res, base-sum[1][i]+sum[0][i]+mv[i&1][i]);
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