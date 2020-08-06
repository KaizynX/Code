/*
 * @Author: Kaizyn
 * @Date: 2020-07-19 18:30:41
 * @LastEditTime: 2020-07-19 18:45:36
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;
const string S = "abacaba";

int n;
string s;

inline bool check(const int &x) {
  string str = s.substr(0, x)+S+s.substr(x+7);
  int cnt = 0;
  for (int i = 0; i < n-6; ++i) cnt += str.substr(i, 7) == S;
  #ifdef DEBUG
  cout << str << " " << cnt << endl;
  #endif
  return cnt == 1;
}

inline void solve() {
  cin >> n >> s;
  for (int i = 0; i+6 < n; ++i) {
    int flag = 1;
    for (int j = 0; j < 7; ++j) {
      if (s[i+j] == '?' || s[i+j] == S[j]) continue;
      flag = 0;
      break;
    }
    if (flag && check(i)) {
      cout << "Yes" << endl;
      for (int j = 0; j < i; ++j) cout << (s[j] == '?' ? 'z' : s[j]);
      cout << S;
      for (int j = i+7; j < n; ++j) cout << (s[j] == '?' ? 'z' : s[j]);
      cout << endl;
      return;
    }
  }
  cout << "No" << endl;
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