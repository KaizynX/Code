/*
 * @Author: Kaizyn
 * @Date: 2021-03-19 23:32:56
 * @LastEditTime: 2021-03-19 23:34:05
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
  vector<int> ptn, enm, siz; // ptntner, enemy
  void init(int n) {
    siz = vector<int>(n+1, 1);
    ptn = enm = vector<int>(n+1, 0);
    iota(ptn.begin(), ptn.end(), 0);
  }
  int get(int s) { while (s != ptn[s]) s = ptn[s]; return s; }
  void merge(int x, int y) {
    x = get(x); y = get(y);
    if (siz[x] > siz[y]) swap(x, y);
    ptn[x] = y;
    siz[y] += x;
  }
  bool update(int x, int y) {
    if(!enm[x] && !enm[y]) { // set this two to oppsite
      enm[x] = y;
      enm[y] = x;
    } else if(!enm[x] && enm[y]) { // set x to y's enemy
      merge(x, enm[y]);
      enm[x] = get(y);
    } else if(enm[x] && !enm[y]) {
      merge(y, enm[x]);
      enm[y] = get(x);
    } else if(get(enm[x]) != get(enm[y])) { // connect(enm[x],ptn[y]) (enm[y],ptn[x])
      merge(y, enm[x]);
      merge(x, enm[y]);
    } else {
      return false;
    }
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