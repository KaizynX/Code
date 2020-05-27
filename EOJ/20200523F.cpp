/*
 * @Author: Kaizyn
 * @Date: 2020-05-23 13:54:43
 * @LastEditTime: 2020-05-23 14:09:23
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
string s[N];

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  sort(s+1, s+n+1);
  reverse(s+1, s+n+1);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << s[i] << endl;
  }
  #endif
  int res = 0;
  for (int i = 1, j; i <= n; ++i) {
    /*
    for (j = 0; j < (int)s[i].size() && j < (int)s[i-1].size(); ++j) {
      if (s[i][j] != s[i-1][j]) break;
    }
    string str = s[i].substr(j);
    if (str.size() >= 4 && str.substr(str.size()-4) == ".eoj") ++res;
    */
    if (s[i].size() >= 4 && s[i].substr(s[i].size()-4) == ".eoj") {
      if (s[i-1].size() > s[i].size() &&
          s[i-1].substr(0, s[i].size()) == s[i] &&
          s[i-1][s[i].size()] == '/') continue;
      ++res;
    }
  }
  cout << res << endl;
  return 0;
}