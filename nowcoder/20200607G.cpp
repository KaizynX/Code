/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 14:03:05
 * @LastEditTime: 2020-06-07 14:07:45
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

int n;
int a[N];

inline void solve() {
  cin >> n;
  int zero = 0, pos = 0, neg = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pos += a[i] > 0;
    zero += a[i] == 0;
    neg += a[i] < 0;
  }
  int res = pos-neg;
  if (zero) res = max(res, 0);
  if (neg&1) res = max({res, pos-1, -1});
  else res = max({res, pos, 1});
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