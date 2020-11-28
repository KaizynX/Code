/*
 * @Author: Kaizyn
 * @Date: 2020-10-29 10:10:50
 * @LastEditTime: 2020-10-29 10:12:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const int N = ;

int a, b, c, d, e;
int s1, s2, s3;

inline void solve() {
  cin >> a >> b >> c >> d >> e;
  s1 = a*a*2;
  s2 = b*c*2;
  s3 = d*e;
  if (s1 > s2 && s1 > s3) {
    cout << "Perch\n";
  } else if (s2 > s1 && s2 > s3) {
    cout << "Semon\n";
  } else {
    cout << "Belinda\n";
  }
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