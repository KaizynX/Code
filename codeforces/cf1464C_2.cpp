/*
 * @Author: Kaizyn
 * @Date: 2020-12-21 22:17:21
 * @LastEditTime: 2020-12-21 22:19:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n;
ll T;
string s;
int cnt[64], add[64];

inline bool solve() {
  cin >> n >> T >> s;
  T -= 1<<(s.back()-'a');
  s.pop_back();
  T += 1<<(s.back()-'a');
  s.pop_back();
  for (char &c : s) ++cnt[c-'a'];
  T = abs(T);
  for (int i = 25; i >= 0; --i) {
    while (cnt[i]--) {
      T += (T < 0 ? 1 : -1)*(1<<i);
    }
  }
  return T == 0;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}
/*
4 1
abaa
*/