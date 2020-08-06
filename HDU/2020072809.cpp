/*
 * @Author: Kaizyn
 * @Date: 2020-07-28 12:30:09
 * @LastEditTime: 2020-07-28 12:41:22
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
string s, ss;
deque<int> q;

inline void solve() {
  cin >> s;
  ss = s;
  n = s.size();
  q.clear();
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      q.push_back(i);
    } else if (s[i] == '(') {
      ++cur;
    } else if (s[i] == ')') {
      --cur;
      if (cur < 0) {
        if (q.empty()) return cout << "No solution!" << endl, void();
        int p = q.front();
        q.pop_front();
        if (p > i) return cout << "No solution!" << endl, void();
        ss[p] = '(';
        ++cur;
      }
    }
  }
  // now cur >= 0
  if ((int)q.size() < cur) return cout << "No solution!" << endl, void();
  for (int i = 1; i <= cur; ++i) {
    int p = q.back();
    q.pop_back();
    ss[p] = ')';
  }
  string res = "";
  cur = 0;
  for (int i = 0; i < n; ++i) {
    if (ss[i] == '*') continue;
    res += ss[i];
    cur += ss[i] == '(' ? 1 : -1;
    if (cur < 0) return cout << "No solution!" << endl, void();
  }
  if (cur != 0) return cout << "No solution!" << endl, void();
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