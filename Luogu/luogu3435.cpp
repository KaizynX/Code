/*
 * @Author: Kaizyn
 * @Date: 2021-08-09 23:40:10
 * @LastEditTime: 2021-08-10 09:54:46
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int n;
int pre[N];
string s;

inline void solve() {
  cin >> n >> s;
  auto z = z_function(s);
  ll res = 0;
  for (int i = 1; i < n; ++i) if (z[i]) {
    // z[i] >= n-i, n <= z[i]+i
    pre[min(i*2, z[i]+i)] = i;
  }
  for (int i = n; i; --i) {
    if (pre[i+1] < i) pre[i] = max(pre[i], pre[i+1]);
  }
  #ifdef DEBUG
  for (int i = 0; i < n; ++i) cout << z[i] << " \n"[i==n-1];
  for (int i = 1; i <= n; ++i) cout << pre[i] << " \n"[i==n];
  #endif
  for (int i = n; i; --i) {
    // if (pre[i+1] < i) pre[i] = max(pre[i], pre[i+1]);
    res += pre[i];
  }
  cout << res << '\n';
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