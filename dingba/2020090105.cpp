/*
 * @Author: Kaizyn
 * @Date: 2020-09-01 21:28:25
 * @LastEditTime: 2020-09-01 21:32:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n, top;
char q[N];
string s;

inline void solve() {
  cin >> n >> s;
  for (const char &c : s) {
    if (top >= 2 && q[top] == q[top-1] && q[top] == c) {
      top -= 2;
    } else {
      q[++top] = c;
    }
  }
  cout << (!top ? "Yes" : "No") << endl;
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