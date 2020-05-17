/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 13:31:44
 * @LastEditTime: 2020-05-10 13:47:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e4+7;

int n, a, b;

inline void solve() {
  cin >> n >> a >> b;
  // if (n == 2) return void(cout << "No") << endl;
  int g = __gcd(a, b);
  cout << (n/g%2 ? "Yes" : "No") << endl;
  /*
  if (a > b) swap(a, b);
  if (b%a == 0) return void(cout << (n/a%2 ? "No" << "Yes") << endl);
  int k = b%a;
  if (a+b > n && b == a*2) return void(cout << "No" << endl);
  */
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