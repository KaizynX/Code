/*
 * @Author: Kaizyn
 * @Date: 2020-05-28 23:04:59
 * @LastEditTime: 2020-05-28 23:19:33
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, k;
int a[N];
int val[N];

inline void solve() {
  cin >> n >> k;
  if (n < k) return cout << 0 << endl, void();
  // if (n == k) return cout << 1 << endl, void();
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      for (int k = j+1; k <= n; ++k) {
        int flag = 1;
        a[1] = i; a[2] = j; a[3] = k;
        for (int l = 1; l <= n; ++l) {
          val[l] = l%a[1]%a[2]%a[3];
        }
        while (next_permutation(a+1, a+4)) {
          for (int l = 1; l <= n; ++l) {
            if (l%a[1]%a[2]%a[3] != val[l]) flag = 0;
          }
        }
        if (flag) {
          cout << i << " " << j << " " << k << endl;
        }
      }
    }
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