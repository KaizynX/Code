/*
 * @Author: Kaizyn
 * @Date: 2020-07-28 11:55:56
 * @LastEditTime: 2020-07-28 12:15:40
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, p;
int cnt[N];

inline void solve() {
  cin >> n >> p;
  for (int i = 0; i < p; ++i) cnt[i] = 0;
  cnt[0] = 1;
  for (int i = 1, s = 0, a; i <= n; ++i) {
    cin >> a;
    s = (s+a)%p;
    ++cnt[s];
  }
  int res = 0;
  for (int i = 0; i < p; ++i) {
    // if (cnt[i] == 1) res = max(res, 1);
    res = max(res, cnt[i]-1);
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