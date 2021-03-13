/*
 * @Author: Kaizyn
 * @Date: 2021-03-12 20:44:02
 * @LastEditTime: 2021-03-12 20:56:52
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
  vector<int> ptn, enm; // ptntner, enemy
  void init(int n) {
    ptn = enm = vector<int>(n+1, 0);
    iota(ptn.begin(), ptn.end(), 0);
  }
  int get(int s) { return s == ptn[s] ? s : ptn[s] = get(ptn[s]); }
  bool merge(int x, int y) {
    if(!enm[x] && !enm[y]) { // set this two to oppsite
      enm[x] = y;
      enm[y] = x;
    } else if(!enm[x] && enm[y]) { // set x to y's enemy
      ptn[x] = get(enm[y]);
      enm[x] = get(y);
    } else if(enm[x] && !enm[y]) {
      ptn[y] = get(enm[x]);
      enm[y] = get(x);
    } else if(get(enm[x]) != get(enm[y])) { // connect(enm[x],py) (enm[y],px)
      ptn[get(y)] = get(enm[x]);
      ptn[get(x)] = get(enm[y]);
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
    if (!dsu.merge(e[i].x, e[i].y)) {
      return cout << e[i].v << '\n', 0;
    }
  }
  cout << "0\n";
  return 0;
}