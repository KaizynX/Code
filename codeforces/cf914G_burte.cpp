/*
 * @Author: Kaizyn
 * @Date: 2020-08-16 14:35:51
 * @LastEditTime: 2020-08-16 14:42:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int B = 2;

int n;
int s[1<<B], aand[1<<B], fib[1<<B];

void print(int *arr) {
  for (int i = 0; i < 1<<B; ++i) printf("%d%c", arr[i], " \n"[i+1==(1<<B)]);
}

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  for (int a = 0; a < n; ++a)
  for (int b = 0; b < n; ++b)
  for (int d = 0; d < n; ++d)
  for (int e = 0; e < n; ++e) {
    aand[(s[a]|s[b])&(s[d]^s[e])] += fib[s[a]|s[b]]*fib[s[d]^s[e]];
  }
  print(aand);
  int res = 0;
  for (int a = 0; a < n; ++a)
  for (int b = 0; b < n; ++b)
  for (int c = 0; c < n; ++c)
  for (int d = 0; d < n; ++d)
  for (int e = 0; e < n; ++e) {
    if (__builtin_popcount((s[a]|s[b])&s[c]&(s[d]^s[e])) == 1) {
      res += fib[s[a]|s[b]]*fib[s[c]]*fib[s[d]^s[e]];
    }
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  fib[0] = 0; fib[1] = 1;
  for (int i = 2; i < 1<<B; ++i) fib[i] = (fib[i-2]+fib[i-1])%MOD;
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}