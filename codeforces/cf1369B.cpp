/*
 * @Author: Kaizyn
 * @Date: 2020-06-23 22:01:35
 * @LastEditTime: 2020-06-23 22:15:21
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
string s;

inline void solve() {
  cin >> n >> s;
  int l = 0, r = n-1;
  while (l < n && s[l] == '0') ++l;
  while (r >= 0 && s[r] == '1') --r;
  if (l >= r) return cout << s << endl, void();
  for (int i = 0; i < l; ++i) cout << '0';
  cout << '0';
  for (int i = r+1; i < n; ++i) cout << '1';
  cout << endl;
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