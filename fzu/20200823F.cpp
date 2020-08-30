/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 15:44:43
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
const int N = 2e6+7;

int n, m, op;
int a[N], vis[N];
vector<int> res;
vector<int> cir[N];

inline void solve1() {
  for (int i = 1; i <= n; ++i) vis[i] = 0;
  for (int i = n, j; i; --i) {
    if (vis[i]) continue;
    vis[i] = 1;
    j = a[i];
    cir[++m].push_back(i);
    while (j != i) {
      vis[j] = 1;
      cir[m].push_back(j);
      j = a[j];
    }
    // rotate(cir[i].begin(), max_element(cir[i].begin(), cir[i].end()), cir[i].end());
  }
  sort(cir+1, cir+m+1);
  res.clear();
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j < (int)cir[i].size(); ++j) res.push_back(cir[i][j]);
  }
  for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i==n-1];
  cout.flush();
}

inline void solve2() {
  for (int i = 1, ma = 0; i <= n; ++i) {
    if (a[i] > ma) {
      ma = a[i];
      ++m;
    }
    cir[m].push_back(a[i]);
  }
  vector<int>(n+1, 0).swap(res);
  for (int i = 1; i <= m; ++i) {
    int sz = cir[i].size();
    for (int j = 0; j < sz; ++j) {
      if (res[cir[i][j]]) return cout << -1 << endl, void();
      res[cir[i][j]] = cir[i][(j+1)%sz];
    }
  }
  for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
  cout.flush();
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> op) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    m = 0;
    op == 1 ? solve1() : solve2();
    for (int i = 1; i <= m; ++i) cir[i].clear();
  }
  return 0;
}