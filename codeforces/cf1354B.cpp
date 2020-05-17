/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 16:43:48
 * @LastEditTime: 2020-05-17 17:28:54
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

string s;
int p[5];

inline void solve() {
  cin >> s;
  memset(p, -1, sizeof p);
  int n = s.size();
  int res = 0;
  for (int i = 0; i < n; ++i) {
    p[s[i]-'0'] = i;
    if (p[1] == -1 || p[2] == -1 || p[3] == -1) continue;
    int cur = i-min({p[1], p[2], p[3]})+1;
    res = res ? min(res, cur) : cur;
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