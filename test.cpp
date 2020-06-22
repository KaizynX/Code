/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditTime: 2020-06-14 14:49:34
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
  int x, y;
  cin >> x >> y;
  int g = __gcd(x, y);
  x /= g; y /= g;
  cout << x << " " << y << endl;
  return 0;
}