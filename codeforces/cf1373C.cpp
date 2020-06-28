/*
 * @Author: Kaizyn
 * @Date: 2020-06-25 22:56:38
 * @LastEditTime: 2020-06-25 22:58:42
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

string s;
int vis[N];

inline void solve() {
  cin >> s;
  long long res =  0;
  for (int i = 0, cur = 0; i < (int)s.size(); ++i) {
    vis[i+1] = 0;
    cur += s[i] == '+' ? 1 : -1;
    if (cur >= 0) continue;
    if (!vis[-cur]) {
      vis[-cur] = 1;
      res += i+1;
    }
  }
  cout << res+s.size() << endl;
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