/*
 * @Author: Kaizyn
 * @Date: 2020-09-01 21:32:54
 * @LastEditTime: 2020-09-01 21:34:33
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
long long m;
string s;

inline void solve() {
  cin >> n >> m >> s;
  m %= 26;
  for (char &c : s) {
    c = (c-'a'-m+26)%26+'a';
  }
  cout << s << endl;
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