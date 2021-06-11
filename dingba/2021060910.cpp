/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 14:47:17
 * @LastEditTime: 2021-06-09 14:51:10
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
const int N = 2e3+7;

int n, c[2];
string s;

void f() {
  int b[2] = {0, 0}, cnt = 0;
  for (int i = 0; i < n*2; ++i) {
    if (s[i] == '1') ++cnt;
    else b[i&1] += cnt, cnt = 0;
  }
  if (b[0] < c[0] || (b[0] == c[0] && b[1] > c[1])) {
    c[0] = b[0];
    c[1] = b[1];
  }
}

inline void solve() {
  cin >> n >> s;
  // c = {2*n, 0};
  c[0] = 2*n+1;
  c[1] = 0;
  f();
  for (int i = 0; i < n*2; ++i) {
    s[i] = ((s[i]-'0')^1)+'0';
    f();
    s[i] = ((s[i]-'0')^1)+'0';
  }
  cout << c[0] << ' ' << c[1] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}