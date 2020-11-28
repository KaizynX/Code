/*
 * @Author: Kaizyn
 * @Date: 2020-10-29 10:22:27
 * @LastEditTime: 2020-10-29 10:42:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n;
long long add[N], del[N];

inline long long solve() {
  memset(add, 0, sizeof add);
  memset(del, 0, sizeof del);
  cin >> n;
  add[1] = 1;
  // del[5] = 1;
  long long cur = 0;
  for (int i = 1; i <= n; ++i) {
    cur += add[i];
    if (i == n) return cur;
    del[i+4] += add[i];
    cur -= del[i];
    for (int j = 2; j <= 4; ++j) {
      add[i+j] += add[i]*4;
      // del[i+j+2] += add[i]*4;
    }
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}