/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 13:06:50
 */
#include <set>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <ctime>
#include <string>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
//#include<chrono>
//#include<unordered_set>
//#include<unordered_map>

// #define DEBUG
using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

long long k;
double a[N];

inline void solve() {
  a[0] = sqrt(2);
  for (int i = 1; i <= 100; ++i) {
    double b = floor(a[i-1]);
    a[i] = b+1/(a[i-1]-b);
    cout << i << " " << a[i] << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  /*
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  */
  while (cin >> k) cout << 2*k << endl;
  return 0;
}