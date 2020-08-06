/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 19:28:57
 * @LastEditTime: 2020-07-17 21:00:38
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
vector<int> p[2];

inline void solve() {
  cin >> s;
  n = s.size();
  p[0].clear();
  p[1].clear();
  int flag = 1, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') {
      ++cur;
      p[0].emplace_back(i);
    } else {
      --cur;
      p[1].emplace_back(i);
    }
    if (cur < 0) flag = 0;
  }
  if (!flag) return cout << "Dead Fang" << endl, void();
  if ((int)p[0].size() == n || p[0].size() == p[1].size()) return cout << "Happy Fang" << endl, void();
  int i = p[0].size()-1;
  while (i >= 0 && p[0][i] > p[1].back()) --i;
  for (int j = p[1].size()-1, i = p[0].size()-1; j >= 0; --j) {
    if (p[0][i] > p[1][j]) return cout << "Sad Fang" << endl, void();
    --i;
  }
  cout << "Happy Fang" << endl;
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