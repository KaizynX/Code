/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 18:59:09
 * @LastEditTime: 2021-08-21 19:09:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

int n, k;

inline bool solve() {
  cin >> n >> k;
  if (n == 1) return 0;
  if (n == 2) return k == 1;
  // if (n == k) return 1;
  // return k%2;
  return k%2 || n==k;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes!" : "No!") << '\n';
  }
  return 0;
}