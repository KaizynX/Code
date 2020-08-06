/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 12:33:25
 * @LastEditTime: 2020-07-27 12:35:48
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e3+7;

int n, k;
int a[N];

inline void solve() {
  cin >> n >> k;
  if (n%2 == 1 && k == 0) {
    cout << n;
    for (int i = 1; i <= n/2; ++i) {
      cout << " " << i << " " << n-i;
    }
    cout << endl;
  } else if (n%2 == 0 && k == n/2) {
    cout << n << " " << n/2;
    for (int i = 1; i < n/2; ++i) {
      cout << " " << i << " " << n-i;
    }
    cout << endl;
  } else {
    cout << -1 << endl;
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