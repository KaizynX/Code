/*
 * @Author: Kaizyn
 * @Date: 2020-06-19 00:33:11
 * @LastEditTime: 2020-06-19 00:34:59
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
int a[N];
int cnt[32];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 0; j < 20; ++j) {
      cnt[j] += (a[i]>>j)&1;
    }
  }
  long long sum = 0;
  for (int i = 1, cur; i <= n; ++i) {
    cur = 0;
    for (int j = 0; j < 20; ++j) {
      if (cnt[j]) {
        --cnt[j];
        cur |= 1<<j;
      }
    }
    sum += 1ll*cur*cur;
  }
  cout << sum << endl;
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