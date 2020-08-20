/*
 * @Author: Kaizyn
 * @Date: 2020-08-14 22:33:04
 * @LastEditTime: 2020-08-14 22:37:02
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

int n;
string s;
map<int, int> mp;

inline void solve() {
  mp.clear();
  cin >> n >> s;
  mp[0] = 1;
  long long res = 0;
  for (int i = 0, a, sum = 0; i < n; ++i) {
    a = s[i]-'0';
    sum += a-1;
    res += mp[sum];
    ++mp[sum];
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