/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 22:17:02
 * @LastEditTime: 2020-08-17 01:29:51
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
long long k;
int a[N];

void f() {
  int mv = -INF;
  for (int i = 1; i <= n; ++i) mv = max(mv, a[i]);
  for (int i = 1; i <= n; ++i) a[i] = mv-a[i];
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  --k; f();
  if (k&1) f();
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
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