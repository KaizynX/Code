/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 22:59:59
 * @LastEditTime: 2020-06-07 23:03:45
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;

int n;
long long a[N];

inline long long solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  if (n == 1) return a[1];
  if (n == 2) return a[1]|a[2];
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      for (int k = j+1; k <= n; ++k) {
        res = max(res, a[i]|a[j]|a[k]);
      }
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}