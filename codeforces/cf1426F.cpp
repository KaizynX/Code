/*
 * @Author: Kaizyn
 * @Date: 2020-12-27 09:46:41
 * @LastEditTime: 2020-12-27 10:18:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
string s;

inline void solve() {
  cin >> n >> s;
  ll c = 0, bc = 0, abc = 0, k = 1;
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == 'a') {
      (abc += bc) %= MOD;
    } else if (s[i] == 'b') {
      (bc += c) %= MOD;
    } else if (s[i] == 'c') {
      (c += k) %= MOD;
    } else {
      abc = (3*abc+bc)%MOD;
      bc = (3*bc+c)%MOD;
      c = (3*c+k)%MOD;
      k = 3*k%MOD;
    }
    cout << c << " " << bc << " " << abc << endl;
  }
  cout << abc << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}