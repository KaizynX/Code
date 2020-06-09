/*
 * @Author: Kaizyn
 * @Date: 2020-06-07 13:25:37
 * @LastEditTime: 2020-06-07 13:33:46
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int n;
string s;

inline void solve() {
  cin >> n;
  int res = 0;
  for (int i = 1, cnt; i <= n; ++i) {
    cin >> s;
    cnt = 0;
    for (const char &c : s) cnt += c == '1';
    res |= cnt&1;
  }
  cout << (res ? "sdzNB" : "kgNB") << endl;
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