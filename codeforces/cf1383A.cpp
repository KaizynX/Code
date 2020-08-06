/*
 * @Author: Kaizyn
 * @Date: 2020-07-24 22:22:47
 * @LastEditTime: 2020-07-24 23:10:36
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M = 22;

struct DSU {
  int fa[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
} dsu;

int n;
string a, b;
int c[M][M], d[M];

inline int solve() {
  cin >> n >> a >> b;
  dsu.init(20);
  memset(c, 0, sizeof c);
  memset(d, 0, sizeof d);
  for (int i = 0; i < n; ++i) {
    if (a[i] > b[i]) return -1;
    if (a[i] == b[i]) continue;
    c[a[i]-'a'][b[i]-'a']++;
  }
  int res = 0;
  for (int i = 19; i >= 0; --i) {
    for (int j = i+1; j < 20; ++j) {
      if (c[i][j]) {
        if (dsu[i] != dsu[j]) {
          dsu.merge(i, j);
          ++res;
        }
      }
    }
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}