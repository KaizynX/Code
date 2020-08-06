/*
 * @Author: Kaizyn
 * @Date: 2020-08-02 22:43:51
 * @LastEditTime: 2020-08-02 23:37:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
const ll INF = 8e18;
const int N = 1e5+7;

int n, m;
ll res[N];

struct Function {
  int a, st, ed;
  ll b;
  ll calc(const ll &x) const {
    return (x-a)*(x-a)*(x-a)*(x-a)+b;
  }
  friend bool operator <(const Function &f1, const Function &f2) {
    return f1.a < f2.a;
  }
} f[N<<1];

struct Query {
  int x, t;
  friend bool operator <(const Query &q1, const Query &q2) {
    return q1.x < q2.x;
  }
} q[N];

struct SegmentTree {
  struct Node {
    int l, r;
    vector<Function> fs;
    vector<Query> qs;
  } tr[N<<2];
  void build(const int &l, const int &r, const int &i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].fs.clear(); tr[i].qs.clear();
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void insert_f(const int &l, const int &r, const Function &k, const int &i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) return tr[i].fs.emplace_back(k), void();
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert_f(l, r, k, i<<1);
    if (r >  mid) insert_f(l, r, k, i<<1|1);
  }
  void insert_q(const int &x, const Query &k, const int &i = 1) {
    tr[i].qs.emplace_back(k);
    if (tr[i].l == tr[i].r) return;
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) insert_q(x, k, i<<1);
    else insert_q(x, k, i<<1|1);
  }
  void solve(const int &i = 1) {
    auto &fs = tr[i].fs;
    auto &qs = tr[i].qs;
    if (fs.size() && qs.size()) {
      /*
      for (int i = 0; i < (int)qs.size(); ++i) {
        if (qs[i].x > fs.front().a) {
          solve1(fs, qs, i, qs.size()-1, 0, fs.size()-1);
          break;
        }
      }
      for (int i = qs.size()-1; i >= 0; --i) {
        if (qs[i].x < fs.back().a) {
          solve2(fs, qs, 0, i, 0, fs.size()-1);
          break;
        }
      }
      */
      solve1(fs, qs, 0, qs.size()-1, 0, fs.size()-1);
      solve2(fs, qs, 0, qs.size()-1, 0, fs.size()-1);
    }
    if (tr[i].l == tr[i].r) {
      if (qs.size()) {
        ll ans = res[qs[0].t];
        printf("%lld\n", ans >= INF ? -1 : ans);
      }
      return;
    }
    solve(i<<1);
    solve(i<<1|1);
  }
  void solve1(const vector<Function> &fs, const vector<Query> &qs,
      const int &l, const int &r, const int &kl, const int &kr) {
    if (l > r) return;
    int k = -1, mid = (l+r)>>1, x = qs[mid].x, t = qs[mid].t;
    for (int i = kl; i <= kr && x >= fs[i].a; ++i) {
      if (k == -1 || fs[i].calc(x) < fs[k].calc(x)) k = i;
    }
    if (~k) res[t] = min(res[t], fs[k].calc(x));
    else k = kl;
    solve1(fs, qs, l, mid-1, kl, k);
    solve1(fs, qs, mid+1, r, k, kr);
  }
  void solve2(const vector<Function> &fs, const vector<Query> &qs,
      const int &l, const int &r, const int &kl, const int &kr) {
    if (l > r) return;
    int k = -1, mid = (l+r)>>1, x = qs[mid].x, t = qs[mid].t;
    for (int i = kr; i >= kl && x <= fs[i].a; --i) {
      if (k == -1 || fs[i].calc(x) < fs[k].calc(x)) k = i;
    }
    if (~k) res[t] = min(res[t], fs[k].calc(x));
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
  int nq = 0;
  tree.build(1, m);
  for (int i = 1, op, x; i <= m; ++i) {
    scanf("%d %d", &op, &x);
    if (op == 1) {
      ++n;
      f[n].a = x;
      scanf("%lld", &f[n].b);
      f[n].st = i; f[n].ed = m;
    } else if (op == 2) {
      f[x].ed = i;
    } else if (op == 3) {
      ++nq;
      q[nq].x = x;
      q[nq].t = i;
      res[i] = INF;
    }
  }
  sort(f+1, f+n+1);
  sort(q+1, q+nq+1);
  for (int i = 1; i <= n; ++i) tree.insert_f(f[i].st, f[i].ed, f[i]);
  for (int i = 1; i <= nq; ++i) tree.insert_q(q[i].t, q[i]);
  tree.solve();
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