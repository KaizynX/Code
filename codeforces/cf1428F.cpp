/*
 * @Author: Kaizyn
 * @Date: 2020-10-17 22:27:28
 * @LastEditTime: 2020-10-17 23:17:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n;
string s;
int h[N], p[N], top;
long long sum[N];

inline void solve() {
  cin >> n >> s;
  long long res = 0;
  for (int i = 1, cur = 0; i <= n; ++i) {
    if (s[i-1] == '0') {
      cur = 0;
      res += sum[top]+(h[top]+1ll)*h[top]/2;
      continue;
    }
    ++cur;
    while (top && cur >= h[top]) --top;
    ++top;
    h[top] = cur;
    p[top] = i-cur;
    sum[top] = sum[top-1];
    if (top == 1) {
      sum[top] += 1ll*cur*(i-cur);
    } else {
      sum[top] += (cur+1ll+h[top-1])*(h[top-1]-cur)/2;
      sum[top] += 1ll*(i-cur-p[top-1]-h[top-1]+cur)*cur;
    }
    res += (1ll+cur)*cur/2+sum[top];
  }
  cout << res << endl;
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