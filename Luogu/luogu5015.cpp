/*
 * @Author: Kaizyn
 * @Date: 2020-09-06 12:52:24
 * @LastEditTime: 2020-09-06 12:53:41
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s;
  int res = 0;
  while (cin >> s) res += s.size();
  cout << res << endl;
  return 0;
}