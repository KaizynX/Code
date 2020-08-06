/*
 * @Author: Kaizyn
 * @Date: 2020-08-02 14:58:53
 * @LastEditTime: 2020-08-02 23:39:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
const int N = 1e5+7;

int n, m;

struct Func {
  int a, st, ed;
  ll b;
  ll calc(const ll &x) const {
    return (x-a)*(x-a)*(x-a)*(x-a)+b;
  }
} f[N<<1];

struct Query {
  int x;
  ll res;
  void update(const ll &val) {
    if (res == -1 || val < res) res = val;
  }
} q[N];

struct SegmentTree {
  struct Node {
    int l, r;
    vector<int> fs, qs;
  } tr[N<<2];
  void build(const int &l, const int &r, const int &i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].fs.clear(); tr[i].qs.clear();
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void insert_f(const int &l, const int &r, const int &k, const int &i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) return tr[i].fs.emplace_back(k), void();
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert_f(l, r, k, i<<1);
    if (r >  mid) insert_f(l, r, k, i<<1|1);
  }
  void insert_q(const int &x, const int &k, const int &i = 1) {
    tr[i].qs.emplace_back(k);
    if (tr[i].l == tr[i].r) return;
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) insert_q(x, k, i<<1);
    else insert_q(x, k, i<<1|1);
  }
  void solve(const int &i = 1) {
    vector<int> &fs = tr[i].fs, &qs = tr[i].qs;
    sort(fs.begin(), fs.end(), [](const int &x, const int &y) {
      return f[x].a < f[y].a;
    });
    sort(qs.begin(), qs.end(), [](const int &x, const int &y) {
      return q[x].x < q[y].x;
    });
    if (fs.size() && qs.size()) {
      solve1(fs, qs, 0, qs.size()-1, 0, fs.size()-1);
      solve2(fs, qs, 0, qs.size()-1, 0, fs.size()-1);
    }
    if (tr[i].l == tr[i].r) return;
    solve(i<<1);
    solve(i<<1|1);
  }
  void solve1(const vector<int> &fs, const vector<int> &qs,
      const int &l, const int &r, const int &kl, const int &kr) {
    if (l > r) return;
    int k = -1, mid = (l+r)>>1, x = q[qs[mid]].x;
    for (int i = kl; i <= kr && x >= f[fs[i]].a; ++i) {
      if (k == -1 || f[fs[i]].calc(x) < f[fs[k]].calc(x)) k = i;
    }
    if (~k) q[qs[mid]].update(f[fs[k]].calc(x));
    else k = kl;
    solve1(fs, qs, l, mid-1, kl, k);
    solve1(fs, qs, mid+1, r, k, kr);
  }
  void solve2(const vector<int> &fs, const vector<int> &qs,
      const int &l, const int &r, const int &kl, const int &kr) {
    if (l > r) return;
    int k = -1, mid = (l+r)>>1, x = q[qs[mid]].x;
    for (int i = kr; i >= kl && x <= f[fs[i]].a; --i) {
      if (k == -1 || f[fs[i]].calc(x) < f[fs[k]].calc(x)) k = i;
    }
    if (~k) q[qs[mid]].update(f[fs[k]].calc(x));
    else k = kr;
    solve2(fs, qs, l, mid-1, kl, k);
    solve2(fs, qs, mid+1, r, k, kr);
  }
} tree;

inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d %lld", &f[i].a, &f[i].b);
    f[i].st = 1; f[i].ed = m;
  }
  tree.build(1, m);
  for (int i = 1, op, x; i <= m; ++i) {
    scanf("%d %d", &op, &x);
    q[i].x = 0; // flag for query
    if (op == 1) {
      ++n;
      f[n].a = x;
      scanf("%lld", &f[n].b);
      f[n].st = i; f[n].ed = m;
    } else if (op == 2) {
      f[x].ed = i-1;
    } else if (op == 3) {
      q[i].x = x;
      q[i].res = -1;
      tree.insert_q(i, i);
    }
  }
  for (int i = 1; i <= n; ++i) if (f[i].st <= f[i].ed) {
    tree.insert_f(f[i].st, f[i].ed, i);
  }
  tree.solve();
  for (int i = 1; i <= m; ++i) if (q[i].x) {
    printf("%lld\n", q[i].res);
  }
}

signed main() {
  // freopen("1008.in", "r", stdin);
  // freopen("my.out", "w", stdout);
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}