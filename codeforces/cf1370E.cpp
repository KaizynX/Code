/*
 * @Author: Kaizyn
 * @Date: 2020-06-20 23:37:04
 * @LastEditTime: 2020-06-21 00:38:41
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
string s, t;
vector<int> vec;
int cnt[2], check[2];

inline void solve() {
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      vec.emplace_back(s[i]-'0');
      ++check[s[i]-'0'];
    }
  }
  if (check[0] != check[1]) return cout << -1 << endl, void();
  int m = vec.size();
  cnt[0] = cnt[1] = 0;
  for (int i = 0; i < m; ++i) {
    if (!cnt[vec[i]^1]) ++cnt[vec[i]];
    else {
      --cnt[vec[i]^1];
      ++cnt[vec[i]];
    }
  }
  cout << cnt[0]+cnt[1] << endl;
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