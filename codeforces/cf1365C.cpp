/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 22:23:15
 * @LastEditTime: 2020-06-07 22:42:17
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N], b[N];
int p[N], cnt[N];

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  for (int i = 0; i < n; ++i) {
    p[b[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    ++cnt[(p[a[i]]-i+n)%n];
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res = max(res, cnt[i]);
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