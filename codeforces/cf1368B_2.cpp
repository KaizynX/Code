/*
 * @Author: Kaizyn
 * @Date: 2020-06-18 22:29:49
 * @LastEditTime: 2020-06-19 00:12:32
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;


long long k;
string sss = "codeforces";
int cnt[100];

inline void solve() {
  cin >> k;
  if (k == 1) return cout << sss << endl, void();
  for (int i = 2; ; ++i) {
    long long cur = 1;
    for (int j = 0; j < 10; ++j) cur *= i;
    if (cur >= k) {
      cnt[i] = 10;
      for (int j = i; j > 1; --j) {
        while (cnt[j] && cur/j*(j-1) >= k) {
          cur = cur/j*(j-1);
          --cnt[j];
          ++cnt[j-1];
        }
      }
      // cout << cnt << endl;
      for (int j = 0, k = i; j < 10; ++j) {
        while (cnt[k] == 0) --k;
        for (int l = 1; l <= k; ++l) cout << sss[j];
        --cnt[k];
      }
      cout << endl;
      return;
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