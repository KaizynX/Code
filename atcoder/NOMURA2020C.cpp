/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 20:11:07
 * @LastEditTime: 2020-05-30 20:52:28
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 1e5+7;

int n;
int a[N];
long long b[N];

inline void solve() {
  cin >> n;
  for (int i = 0; i <= n; ++i) cin >> a[i];
  long long cur = 1;
  for (int i = 0; i <= n; ++i) {
    if (a[i] > cur) return cout << -1 << endl, void();
    b[i] = cur;
    cur -= a[i];
    cur = min(cur*2, INF);
  }
  cur = 0;
  long long res = 0;
  for (int i = n; i >= 0; --i) {
    cur += a[i];
    cur = min(cur, b[i]);
    res += cur;
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