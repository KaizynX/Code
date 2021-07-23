/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 15:10:42
 * @LastEditTime: 2021-07-22 15:12:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

int min_cyclic_string(const string &s) {
  int k = 0, i = 0, j = 1, n = s.size();
  while (k < n && i < n && j < n) {
    if (s[(i + k) % n] == s[(j + k) % n]) {
      k++;
    } else {
      s[(i + k) % n] > s[(j + k) % n] ? i = i + k + 1 : j = j + k + 1;
      if (i == j) i++;
      k = 0;
    }
  }
  return min(i, j);
}

string s;

inline void solve() {
  cin >> s;
  cout << min_cyclic_string(s)+1 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}