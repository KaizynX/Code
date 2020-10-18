/*
 * @Author: Kaizyn
 * @Date: 2020-10-09 22:55:00
 * @LastEditTime: 2020-10-11 20:29:25
 */
#include <bits/stdc++.h>

#define DEBUG

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
struct ZYFK { // 值域分块,下标从1开始
  int n, block, rev;
  T a[N], s[N], t[(int)sqrt(N)+3];
  void init(int n, int rev = 0) {
    this->n = n;
    this->rev = rev;
    block = sqrt(n);
    memset(a, 0, sizeof(int)*(n+2));
    memset(s, 0, sizeof(int)*(n+2));
    memset(t, 0, sizeof(int)*((n+1)/block+1));
  }
  void init(int n, T a[], int rev = 0) {
    this-n = n;
    this->rev = rev;
    block = sqrt(n);
    memcpy(this->a+1, a+1, sizeof(int)*n);
    s[n+1] = s[0] = 0;
    if (rev) for (int i = n; i; --i) s[i] = s[i+1]+a[i];
    else for (int i = 1; i <= n; ++i) s[i] = s[i-1]+a[i];
    memset(t, 0, sizeof(int)*((n+1)/block+1));
  }
  void add(int x, T k) {
    a[x] += k;
    if (rev) {
      for (int i = x; i >= i/block*block && i; --i) s[i] += k;
      for (int i = x/block-1; i >= 0; --i) t[i] += k;
    } else {
      for (int i = x; i < (i/block+1)*block && i <= n; ++i) s[i] += k;
      for (int i = x/block+1; i <= n/block; ++i) t[i] += k;
    }
  }
  void modify(int x, T k) {
    add(x, k-a[x]);
  }
  T query(int x) {
    return t[x/block]+s[x];
  }
  T query(int l, int r) {
    return rev ? query(l)-query(r+1) : query(r)-query(l-1);
  }
};

int n, m, block;
int a[N];
long long res[N], sumil[N], sumir[N];
Query q[N];
ZYFK<int> suml, sumr;
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
    sumil[i] = sumil[i-1]+tree.query(a[i]+1, n);
    tree.add(a[i], 1);
  }
  tree.clear();
  for (int i = n; i; --i) {
    sumir[i] = sumir[i+1]+tree.query(1, a[i]-1);
    tree.add(a[i], 1);
  }
}

signed main() {
  read(n); read(m);
  for (int i = 1; i <= n; ++i) read(a[i]);
  discrete();
  block = n/sqrt(m)+1;
  for (int i = 1; i <= m; ++i) {
    q[i].id = i;
    read(q[i].l);
    read(q[i].r);
  }
  sort(q+1, q+m+1, cmp);
  calc_sumi();
  #ifdef DEBUG
  cout << "sumil:";
  for (int i = 1; i <= n; ++i) cout << sumil[i] << " \n"[i==n];
  cout << "sumir:";
  for (int i = 1; i <= n; ++i) cout << sumir[i] << " \n"[i==n];
  cout << "***********" << endl;
  #endif
  for (int i = 1, l = 1, r = 0; i <= m; ++i) {
    res[i] = sumil[q[i].r]-sumil[r]+sumir[q[i].l]-sumir[l];
    if (r < q[i].r) ql[l-1].emplace_back(i, r+1, q[i].r);
    if (r > q[i].r) ql[l-1].emplace_back(-i, q[i].r+1, r);
    r = q[i].r;
    if (l > q[i].l) qr[r+1].emplace_back(i, l-1, q[i].l);
    if (l < q[i].l) qr[r+1].emplace_back(-i, q[i].l-1, l);
    l = q[i].l;
  }
  suml.init(n, 0);
  for (int i = 1; i <= n; ++i) {
    suml.add(a[i], 1);
    for (auto &qq : ql[i]) {
      for (int j = qq.l; j <= qq.r; ++j) {
        if (qq.id > 0) res[qq.id] += suml.query(a[j]+1);
        else res[-qq.id] -= suml.query(a[j]+1);
      }
    }
  }
  sumr.init(n, 1);
  for (int i = n; i; --i) {
    sumr.add(a[i], 1);
    for (auto &qq : ql[i]) {
      for (int j = qq.l; j <= qq.r; ++j) {
        if (qq.id > 0) res[qq.id] += sumr.query(a[j]-1);
        else res[-qq.id] -= sumr.query(a[j]-1);
      }
    }
  }
  for (int i = 1; i <= m; ++i) res[i] += res[i-1];
  for (int i = 1; i <= m; ++i) {
    write(res[q[i].id]);
    putchar(" \n"[i==m]);
  }
  return 0;
}
/*
4 10
1 4 2 3
1 1
1 2
1 3
1 4
2 2
2 3
2 4
3 3
3 4
4 4
*/