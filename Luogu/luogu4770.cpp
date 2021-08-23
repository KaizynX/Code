/*
 * @Author: Kaizyn
 * @Date: 2021-08-23 16:13:58
 * @LastEditTime: 2021-08-23 18:59:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;
const int NLOG = 2e7+7;

template <typename T>
struct Tree {
  int tot, lc[NLOG], rc[NLOG];
  T tr[NLOG];
  void init() { tot = 0; }
  T giao(const T &x, const T &y) { return max(x, y); }
  void push_up(int i) { tr[i] = giao(tr[lc[i]], tr[rc[i]]); }
  int new_node(T v = 0) {
    ++tot; // assert(++tot < NLOG);
    lc[tot] = rc[tot] = 0;
    tr[tot] = v;
    return tot;
  }
  void add(int x, int l, int r, int &i) {
    if (!i) i = new_node();
    if (l == r) return tr[i] = l, void();
    int mid = (l+r)>>1;
    if (x <= mid) add(x, l, mid, lc[i]);
    else add(x, mid+1, r, rc[i]);
    push_up(i);
  }
  /*
  void merge(int l, int r, int &x, int &y) { // merge y to x
    if (!x || !y) return x += y, void();
    if (l == r) return tr[x] += tr[y], void();
    int mid = (l+r)>>1;
    merge(l, mid, lc[x], lc[y]);
    merge(mid+1, r, rc[x], rc[y]);
    push_up(x); // del(y);
  }
  */
  int merge(int l, int r, int x, int y) { // new node
    if (!x || !y) return x += y;
    int cur = new_node(), mid = (l+r)>>1;
    if (l == r) return tr[cur] = tr[x]+tr[y], cur;
    lc[cur] = merge(l, mid, lc[x], lc[y]);
    rc[cur] = merge(mid+1, r, rc[x], rc[y]);
    push_up(cur);
    return cur;
  }
  T query(int x, int l, int r, int i) { // <= x
    if (!i) return 0;
    if (r <= x) return tr[i];
    int mid = (l+r)>>1;
    if (x <= mid) return query(x, l, mid, lc[i]);
    return giao(query(x, l, mid, lc[i]), query(x, mid+1, r, rc[i]));
  }
  T query(int L, int R, int l, int r, int i) {
    if (!i) return 0;
    if (L <= l && r <= R) return tr[i];
    int mid = (l+r)>>1;
    if (R <= mid) return query(L, R, l, mid, lc[i]);
    if (L >  mid) return query(L, R, mid+1, r, rc[i]);
    return giao(query(L, R, l, mid, lc[i]), query(L, R, mid+1, r, rc[i]));
  }
};

int n, q;
int rt[N<<1];
Tree<int> tree;

struct SAM { // root 0
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  int t[M], rk[M], cnt[M];
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    memset(cnt, 0, sizeof(int)*sz);
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert(const string &s) {
    init(); for (char ch : s) last = extend(ch-C);
  }
  void build() { // topo on parent tree
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
  }
  void solve1(const string &s) {
    tree.init();
    for (int i = 0, last = 0; i < (int)s.size(); ++i) {
      last = nex[last][s[i]-C];
      tree.add(i+1, 1, n, rt[last]);
    }
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      rt[j] = tree.merge(1, n, rt[j], rt[i]);
    }
  }
  ll solve2() {
    ll ans = 0;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      cnt[j] = max(cnt[j], cnt[i]);
      ans -= max(0, min(cnt[i], len[i])-len[j]);
      ans += len[i]-len[j];
    }
    return ans;
  }
};

string s, t;
SAM sams, samt;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> s >> q;
  n = s.size();
  sams.insert(s);
  sams.build();
  sams.solve1(s);
  #ifdef DEBUG
  cout << tree.query(7, 1, n, rt[9]) << '\n';
  #endif
  for (int _ = q, l, r, c, si, ti, len; _; --_) {
    cin >> t >> l >> r;
    samt.insert(t);
    samt.build();
    si = ti = len = 0;
    for (char ch : t) {
      c = ch-'a';
      ti = samt.nex[ti][c];
      while (si && !sams.nex[si][c]) len = sams.len[si = sams.link[si]];
      if (sams.nex[si][c]) si = sams.nex[si][c], ++len;
      while (si && tree.query(r, 1, n, rt[si])-l+1 < len) {
        if (--len <= sams.len[sams.link[si]]) si = sams.link[si];
      }
      samt.cnt[ti] = len; 
      #ifdef DEBUG
      orz(c); orz(len); orz(si);
      #endif
    }
    cout << samt.solve2() << '\n';
  }
  return 0;
}