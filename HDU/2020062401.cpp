/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 18:26:47
 * @LastEditTime: 2020-06-24 18:32:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

string s;
int n;
int a[N];

inline void solve() {
  cin >> s;
  cin >> n;
  int minv = 222222, maxv = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    minv = min(minv, a[i]);
    maxv = max(maxv, a[i]);
  }
  if (s == "Faster") cout << minv << endl;
  else cout << maxv << endl;
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