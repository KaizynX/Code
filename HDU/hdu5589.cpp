/*
 * @Author: Kaizyn
 * @Date: 2020-05-19 16:42:23
 * @LastEditTime: 2020-05-20 20:33:29
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;
const int B = 16;

int n, m, q, t;
int a[N];
long long res[N];
vector<pii> e[N];

struct TireTree {
  static const int NN = N*B*2;
  static const int SZ = 2;
  int nex[NN][SZ], num[NN], cnt;
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num+1, 0, sizeof(int)*cnt);
    cnt = 0;
  }
  void insert(const int &x) {
    for (int c, p = 0, b = 15; b >= 0; --b) {
      c = (x>>b)&1;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
      ++num[p];
    }
  }
  void erase(const int &x) {
    for (int c, p = 0, b = 15, q; b >= 0; --b) {
      c = (x>>b)&1;
      q = nex[p][c];
      if (--num[q] == 0) nex[p][c] = 0;
      p = q;
    }
  }
  int count(const int &x) {
    int cnt = 0;
    for (int b = 15, c, d, p = 0; b >= 0; --b) {
      c = (x>>b)&1;
      d = (m>>b)&1;
      if (!d) cnt += num[nex[p][c^1]];
      p = nex[p][c^d];
      if (!p) break;
    }
    return cnt;
  }
} tire_tree;

struct Query {
  int l, r, id;
  friend bool operator <(const Query &lhs, const Query &rhs) {
    return (lhs.l-1)/t == (rhs.l-1)/t ? lhs.r < rhs.r : lhs.l < rhs.l;
  }
} qq[N];

void tree_bfs() {
  static queue<int> q;
  memset(a+1, -1, sizeof(int)*n);
  a[1] = 0;
  q.push(1);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (const pii &v : e[u]) {
      if (a[v.first] != -1) continue;
      a[v.first] = a[u]^v.second;
      q.push(v.first);
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (scanf("%d %d %d", &n, &m, &q) == 3) {
    for (int i = 1, u, v, w; i < n; ++i) {
      scanf("%d %d %d", &u, &v, &w);
      e[u].emplace_back(v, w);
      e[v].emplace_back(u, w);
    }
    for (int i = 1; i <= q; ++i) {
      scanf("%d %d", &qq[i].l, &qq[i].r);
      qq[i].id = i;
    }

    tree_bfs();
#ifdef DEBUG
    for (int i = 1; i <= n; ++i) printf("%d%c", a[i], " \n"[i==n]);
#endif
    t = sqrt(n)+.5;
    sort(qq+1, qq+q+1);
    for (int i = 0, j = 1; i <= n/t; ++i) {
      tire_tree.clear();
      long long cnt = 0;
      for (int l = i*t+1, r = i*t; j <= q && (qq[j].l-1)/t == i; ++j) {
        while (r < qq[j].r) {
          cnt += tire_tree.count(a[++r]);
          tire_tree.insert(a[r]);
        }
        while (l > qq[j].l) {
          cnt += tire_tree.count(a[--l]);
          tire_tree.insert(a[l]);
        }
        while (l < qq[j].l) {
          tire_tree.erase(a[l]);
          cnt -= tire_tree.count(a[l++]);
        }
        res[qq[j].id] = cnt;
      }
    }
    for (int i = 1; i <= q; ++i) printf("%lld\n", res[i]);

    for (int i = 1; i <= n; ++i) vector<pii>().swap(e[i]);
  }
  return 0;
}