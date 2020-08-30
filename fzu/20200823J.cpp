/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 13:28:56
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
typedef unsigned long long ull;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int p, q, m, res;
map<ull, int> mp;

void insert(const ull &val) {
  if (++mp[val] == 1) ++res;
}

void erase(const ull &val) {
  if (--mp[val] == 0) --res;
}

inline void solve() {
  mp.clear();
  ull num;
  for (int i = 1; i <= p; ++i) {
    cin >> num;
    insert(num);
  }
  for (int i = 1; i <= q; ++i) {
    cin >> num;
    insert(num);
  }
  cin >> m;
  for (int i = 1, opt; i <= m; ++i) {
    cin >> opt;
    if (opt == 5) {
      cout << res << endl;
      continue;
    }
    cin >> num;
    if (opt <= 3) insert(num);
    else erase(num);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> p >> q) solve();
  /*
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  */
  return 0;
}