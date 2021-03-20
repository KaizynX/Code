/*
 * @Author: Kaizyn
 * @Date: 2021-03-20 21:43:30
 * @LastEditTime: 2021-03-20 22:18:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

struct Node {
  int x, y, v;
  bool operator < (const Node &b) const { return v < b.v;}
};

struct DSU {
  int n;
  vector<int> fa; // [1, n] partner, [n+1, 2n] enemy
  void init(int n) {
    this->n = n;
    fa = vector<int>(2*n+1, 0);
    iota(fa.begin(), fa.begin()+n+1, 0);
  }
  int get(int s) { return !fa[s] || s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  void merge(int x, int y) { fa[get(x)] = get(y); }
  bool update(int x, int y) {
    if (get(x) == get(y)) return false;
    merge(x+n, y);
    merge(x, y+n);
    return true;
  }
};

int n, m;
DSU dsu;
Node e[N];

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n >> m;
  for(int i = 0; i < m; ++i) cin >> e[i].x >> e[i].y >> e[i].v;
  sort(e, e+m);
  reverse(e, e+m);
  dsu.init(n);
  for(int i = 0; i < m; ++i) {
    if (!dsu.update(e[i].x, e[i].y)) {
      return cout << e[i].v << '\n', 0;
    }
  }
  cout << "0\n";
  return 0;
}