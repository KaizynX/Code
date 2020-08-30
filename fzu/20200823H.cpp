/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 16:25:30
 * @LastEditTime: 2020-08-23 16:50:45
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
const int N = 1e2+7;

long long n, m, v;

inline bool solve() {
  cin >> n >> m >> v;
  if (n > m) swap(n, m);
  if (v == 2) return n;
  if (n == 0) return 1;
  if (n == 1) return m%2 == 0;
  if (n == 2) return 1;
  return 0;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T;
  while (cin >> T) {
    while (T--) cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}