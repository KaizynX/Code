/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 19:58:06
 * @LastEditTime: 2020-06-21 17:36:14
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

int n, k;
int a[N];
int add[N];

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int t = 1, cnt; t <= k; ++t) {
    memset(add+1, 0, sizeof(int)*n);
    for (int i = 1; i <= n; ++i) {
      ++add[max(1, i-a[i])];
      --add[min(n+1, i+a[i]+1)];
    }
    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = a[i-1]+add[i];
      cnt += a[i] == n;
    }
    if (cnt == n) break;
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i==n];
  }
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