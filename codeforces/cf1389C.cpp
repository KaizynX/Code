/*
 * @Author: Kaizyn
 * @Date: 2020-07-29 22:31:22
 * @LastEditTime: 2020-07-29 23:12:14
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

int n;
int a[N], nex[N][10];
string s;

inline void solve() {
  cin >> s;
  n = s.size();
  for (int i = 1; i <= n; ++i) a[i] = s[i-1]-'0';
  for (int j = 0; j < 10; ++j) nex[n+1][j] = n+1;
  for (int i = n; i; --i) {
    for (int j = 0; j < 10; ++j) nex[i][j] = nex[i+1][j];
    nex[i][a[i]] = i;
  }
  int res = 0;
  for (int s1 = 0; s1 < 10; ++s1) {
    int cnt = 0, i = 1;
    while (i <= n) {
      i = nex[i][s1];
      if (i > n) break;
      ++i;
      ++cnt;
    }
    res = max(res, cnt);
  }
  for (int s1 = 0; s1 < 10; ++s1) {
    for (int s2 = 0; s2 < 10; ++s2) {
      int cnt = 0, i = 1;
      while (i <= n) {
        i = nex[i][s1];
        if (i > n) break;
        ++i;
        i = nex[i][s2];
        if (i > n) break;
        ++i;
        cnt += 2;
      }
      res = max(res, cnt);
    }
  }
  cout << n-res << endl;
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