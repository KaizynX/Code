/*
 * @Author: Kaizyn
 * @Date: 2020-08-23 12:40:06
 * @LastEditTime: 2020-08-23 14:16:24
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
const int N = 1e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return x > y ? 0 : query(y)-query(x-1); }
};

int n;
int a[N];
long long pre[N];
BinaryIndexedTree<int> bit;

inline long long solve() {
  for (int i = 1; i <= n; ++i) cin >> a[i];
  bit.init(n);
  for (int i = 1; i < n; ++i) {
    pre[i] = pre[i-1]+bit.query(a[i]+1, n);
    bit.add(a[i], 1);
  }
  bit.init(n);
  long long res = 0, suf = 0;
  for (int i = n; i > 1; --i) {
    suf += bit.query(1, a[i]-1);
    bit.add(a[i], 1);
    res = max(res, pre[i-1]+suf);
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) cout << solve() << endl;
  /*
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  */
  return 0;
}