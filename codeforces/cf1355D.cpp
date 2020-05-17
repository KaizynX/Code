/*
 * @Author: Kaizyn
 * @Date: 2020-05-16 19:25:50
 * @LastEditTime: 2020-05-16 20:33:45
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

int n, s;

inline void solve() {
  cin >> n >> s;
  if (s < n*2) return void(cout << "NO" << endl);
  cout << "YES\n";
  for (int i = 1; i < n; ++i) {
    cout << 2 << " ";
  }
  cout << s-(n-1)*2 << endl << 1 << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}