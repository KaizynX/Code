/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 14:25:36
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

int n, m;

inline int solve() {
  if (n*m%2 == 1) return 0;
  if (n > m) swap(n, m);
  if (n == 1) return (m/2+1)*(m/2)/2;
  if (n%2 == 1) swap(n, m);
  return n/2*m*n/2*m;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) cout << solve() << endl;
  /*
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  */
  return 0;
}