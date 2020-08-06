/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 19:28:57
 * @LastEditTime: 2020-07-17 19:38:09
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
string s;

inline void solve() {
  cin >> s;
  n = s.size();
  int cnt[2] = {0, 0};
  int flag = 1, cur = 0;
  for (int i = 0; i < n; ++i) {
    ++cnt[s[i]-'a'];
    if (s[i] == 'a') ++cur;
    else --cur;
    if (cur < 0) flag = 0;
  }
  if (!flag) return cout << "Dead Fang" << endl, void();
  if (cnt[0] == n || cnt[0] == cnt[1]) return cout << "Happy Fang" << endl, void();
  cout << "Sad Fang" << endl;
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