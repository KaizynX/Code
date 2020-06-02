/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 12:39:23
 * @LastEditTime: 2020-05-30 12:43:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n, m;
string s[N];

inline int solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) cin >> s[i];
  sort(s+1, s+m+1);
  m = unique(s+1, s+m+1)-s-1;
  sort(s+1, s+m+1, [](string &s1, string &s2) {
      return s1.size() < s2.size();
  });
  if (n < (int)s[1].size()) return 0;
  int cur = s[1].size(), cnt = 1;
  for (int i = 2; i <= m; ++i) {
    if (cur+1+(int)s[i].size() <= n) {
      cur += s[i].size()+1;
      ++cnt;
    }
  }
  return cnt;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}