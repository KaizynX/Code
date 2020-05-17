/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 10:14:11
 * @LastEditTime: 2020-05-15 10:35:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, k;
string s;

inline void solve() {
  cin >> n >> k >> s;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += s[i] == '1';
  }
  int res = sum;
  for (int i = 0; i < k; ++i) {
    int cnt = 0, cur = 0;
    for (int j = i; j < n; j += k) {
      cnt += s[j] == '1' ? 1 : -1;
      cnt = max(cnt, 0);
      cur = max(cnt, cur);
    }
    res = min(res, sum-cur);
  }
  cout << res << endl;
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