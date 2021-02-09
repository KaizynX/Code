/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:06:34
 * @LastEditTime: 2021-01-14 10:10:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;
/*
1. 如果三条边都相等,则称为"等边三角形"(equilateral);
2. 如果一个三角形不是等边的,但是其中某2条边相等,则称为"等腰三角形"(isosceles);
3. 如果一个三角形所有边都不相等,则称为"不规则三角形"(scalene).
*/

inline string solve() {
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  if (a[0]+a[1] <= a[2]) return "invalid!";
  if (a[0] == a[1] && a[0] == a[2]) return "equilateral";
  if (a[0] == a[1] || a[1] == a[2]) return "isosceles";
  return "scalene";
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}