/*
 * @Author: Kaizyn
 * @Date: 2020-10-09 22:55:00
 * @LastEditTime: 2020-10-12 15:49:59
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

template <typename T> inline void read(T &x) {
  int c; T tag = 1;
  while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
  x *= tag;
}

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

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
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

struct Query {
  int id, l, r;
  Query() {}
  Query(int i, int _l, int _r) : id(i), l(_l), r(_r) {}
};

template <typename T>
struct PreSum {
  int n, block;
  T s[N], t[(int)sqrt(N)+3];
  void init(int n) {
    this->n = n;
    block = sqrt(n);
  }
  void add(int x, T k) {
    for (int i = x; i/block == x/block && i <= n; ++i) s[i] += k;
    for (int i = x/block+1; i <= n/block; ++i) t[i] += k;
  }
  T query(int x) {
    return t[x/block]+s[x];
  }
};

template <typename T>
struct SufSum {
  int n, block;
  T s[N], t[(int)sqrt(N)+3];
  void init(int n) {
    this->n = n;
    block = sqrt(n);
  }
  void add(int x, T k) {
    for (int i = x; i/block == x/block && i >= 1; --i) s[i] += k;
    for (int i = x/block-1; i >= 0; --i) t[i] += k;
  }
  T query(int x) {
    return t[x/block]+s[x];
  }
};

int n, m, block;
int a[N];
long long res[N], sumil[N], sumir[N], ans[N];
Query q[N];
SufSum<int> suml;
PreSum<int> sumr;
vector<Query> ql[N], qr[N];

inline void discrete() {
  static int d[N];
  memcpy(d+1, a+1, sizeof(int)*n);
  sort(d+1, d+n+1);
  int dn = unique(d+1, d+n+1)-d-1;
  for (int i = 1; i <= n; ++i)
    a[i] = lower_bound(d+1, d+dn+1, a[i])-d;
}

inline bool cmp(const Query &q1, const Query &q2) {
  return q1.l/block != q2.l/block ? q1.l < q2.l :
      (q1.l/block)&1 ? q1.r < q2.r : q1.r > q2.r;
}

inline void calc_sumi() {
  static BinaryIndexedTree<int> tree;
  tree.init(n);
  for (int i = 1; i <= n; ++i) {
    sumil[i] = sumil[i-1]+i-1-tree.query(a[i]);
    tree.add(a[i], 1);
  }
  tree.clear();
  for (int i = n; i; --i) {
    sumir[i] = sumir[i+1]+tree.query(a[i]-1);
    tree.add(a[i], 1);
  }
}

signed main() {
  read(n); read(m);
  for (int i = 1; i <= n; ++i) read(a[i]);
  discrete();
  block = n/sqrt(m);
  for (int i = 1; i <= m; ++i) {
    q[i].id = i;
    read(q[i].l);
    read(q[i].r);
  }
  sort(q+1, q+m+1, cmp);
  calc_sumi();
  q[0] = Query(0, 1, 0);
  for (int i = 1, ul, vl, ur, vr; i <= m; ++i) {
    ul = q[i-1].l; ur = q[i-1].r;
    vl = q[i].l; vr = q[i].r;
    res[i] = sumil[vr]-sumil[ur]+sumir[vl]-sumir[ul];
    if (vl < ul) qr[vr+1].emplace_back(-i, vl, ul-1);
    if (vl > ul) qr[vr+1].emplace_back(+i, ul, vl-1);
    if (vr < ur) ql[ul-1].emplace_back(+i, vr+1, ur);
    if (vr > ur) ql[ul-1].emplace_back(-i, ur+1, vr);
  }
#ifdef DEBUG
  cout << "sumil:";
  for (int i = 1; i <= n; ++i) cout << sumil[i] << " \n"[i==n];
  cout << "sumir:";
  for (int i = 1; i <= n; ++i) cout << sumir[i] << " \n"[i==n];
  cout << "res:";
  for (int i = 1; i <= m; ++i) cout << res[i] << " \n"[i==m];
  cout << "***********" << endl;
#endif
  suml.init(n+1);
  for (int i = 1; i <= n; ++i) {
    suml.add(a[i], 1);
    for (auto &qq : ql[i]) {
      for (int j = qq.l; j <= qq.r; ++j) {
        if (qq.id > 0) res[qq.id] += suml.query(a[j]+1);
        else res[-qq.id] -= suml.query(a[j]+1);
      }
#ifdef DEBUG
      printf("%d (%d %d %d) %lld\n", i, qq.id, qq.l, qq.r, res[abs(qq.id)]);
#endif
    }
  }
#ifdef DEBUG
  cout << "res:";
  for (int i = 1; i <= m; ++i) cout << res[i] << " \n"[i==m];
#endif
  sumr.init(n);
  for (int i = n; i; --i) {
    sumr.add(a[i], 1);
    for (auto &qq : qr[i]) {
      for (int j = qq.l; j <= qq.r; ++j) {
        if (qq.id > 0) res[qq.id] += sumr.query(a[j]-1);
        else res[-qq.id] -= sumr.query(a[j]-1);
      }
    }
  }
#ifdef DEBUG
  cout << "res:";
  for (int i = 1; i <= m; ++i) cout << res[i] << " \n"[i==m];
#endif
  for (int i = 1; i <= m; ++i) {
    res[i] += res[i-1];
    ans[q[i].id] = res[i];
  }
  for (int i = 1; i <= m; ++i) {
    write(ans[i]);
    putchar('\n');
  }
  return 0;
}