/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 14:40:46
 * @LastEditTime: 2020-08-29 14:58:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n;
int a[N];

inline bool solve() {
  stack<int> stk;
  cin >> n;
  // int p1, pn;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    // if (a[i] == 1) p1 = i;
    // if (a[i] == n) pn = i;
  }
  for (int i = 1; i < n; ++i) {
    if (stk.empty() || stk.top() > a[i]) stk.push(a[i]);
  }
  while (stk.size()) {
    if (stk.top() > a[n]) return 0;
    stk.pop();
  }
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}