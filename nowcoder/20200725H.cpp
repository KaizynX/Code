/*
 * @Author: Kaizyn
 * @Date: 2020-07-25 15:20:36
 * @LastEditTime: 2020-07-26 09:50:36
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

template <typename T>
struct ST {
  static const int NN = (int)log2(N)+3;
  int lg2[N];
  T rmq[N][NN];
  ST() { for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1; }
  T& operator [] (const int &i) { return rmq[i][0]; }
  T mv(const T &x, const T &y) { return x&y; }
  // rmq[i][j] ==> [i, i+2^j-1]
  void build(T a[], const int &n) {
    for (int i = n; i; --i) {
      rmq[i][0] = a[i];
      for (int j = 1; j <= lg2[n-i+1]; ++j)
        rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  T query(const int &l, const int &r) {
    if (l > r) return query(r, l);
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

struct PersistenceSegmentTree {
  static const int NN = 30*N*(log2(30*N)+3);
  int rt[N], sum[NN], ls[NN], rs[NN], tot, sz;
  void build(const int &n) {
    sz = n;
    tot = 0;
    rt[0] = _build(1, sz);
  }
  void update(const int &id, const int &k) {
    rt[id] = _update(rt[id-1], 1, sz, k);
  }
  // 查询区间内大于k的个数
  int query(const int &l, const int &r, const int &k) const {
    return _query(rt[l-1], rt[r], 1, sz, k);
  }
private:
  int _build(const int &l, const int &r) {
    int cur = ++tot;
    sum[cur] = 0;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    ls[cur] = _build(l, mid);
    rs[cur] = _build(mid+1, r);
    return cur;
  }
  int _update(const int &pre, const int &l, const int &r, const int &k) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k);
    else rs[cur] = _update(rs[pre], mid+1, r, k);
    return cur;
  }
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) const {
    if (l >= r) return 0;
    int mid = (l+r)>>1;
    if (k <= mid) return _query(ls[u], ls[v], l, mid, k)+sum[rs[v]]-sum[rs[u]];
    else return _query(rs[u], rs[v], mid+1, r, k);
  }
};

int n, q;
int a[N];
ST<int> st;
vector<pii> add, del;
unordered_map<int, vector<pii>> mp;
PersistenceSegmentTree add_pst, del_pst;

// 返回[l,r]区间内 区间的个数
inline int count(const int &l, const int &r, const vector<pii> &vec, const PersistenceSegmentTree &pst) {
  int s = lower_bound(vec.begin(), vec.end(), pii{l, l})-vec.begin()+1;
  int t = upper_bound(vec.begin(), vec.end(), pii{r, r})-vec.begin();
  return (t-s+1)-pst.query(s, t, r);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  mp.clear();
  st.build(a, n);
  for (int i = 1; i <= n; ++i) {
    int j = i;
    mp[a[i]].emplace_back(i, i);
    // 对于每个不同的值找到最小的区间[i,j]
    while (j < n) {
      int l = j+1, r = n, mid;
      while (l < r) {
        mid = (l+r)>>1;
        if (st.query(i, mid) == st.query(i, j)) l = mid+1;
        else r = mid;
      }
      if (st.query(i, j) == st.query(i, l)) break;
      j = l;
      mp[st.query(i, j)].emplace_back(i, j);
    }
  }
  add.clear();
  del.clear();
  vector<pii> vv;
  vector<int> que;
  for (auto &mmp : mp) {
    vector<pii> &vec = mmp.second;
    sort(vec.begin(), vec.end());
    que.clear();
    vv.clear();
    // 去掉包含关系的区间
    for (int i = 0; i < (int)vec.size(); ++i) {
      while (que.size() && vec[que.back()].second >= vec[i].second) {
        que.pop_back();
      }
      que.push_back(i);
    }
    // 同一个值多个区间去重
    for (int i = 0; i < (int)que.size(); ++i) {
      add.emplace_back(vec[que[i]]);
      if (i) del.emplace_back(vec[que[i-1]].first, vec[que[i]].second);
    }
  }
  sort(add.begin(), add.end());
  sort(del.begin(), del.end());
  add_pst.build(n);
  del_pst.build(n);
  for (int i = 0; i < (int)add.size(); ++i)
    add_pst.update(i+1, add[i].second);
  for (int i = 0; i < (int)del.size(); ++i)
    del_pst.update(i+1, del[i].second);
  #ifdef DEBUG
  for (const pii &pr : add) printf("(%d,%d)", pr.first, pr.second);
  puts("");
  for (const pii &pr : del) printf("(%d,%d)", pr.first, pr.second);
  puts("");
  #endif

  cin >> q;
  for (int i = 1, l, r, lastans = 0; i <= q; ++i) {
    cin >> l >> r;
    l = (l^lastans)%n+1;
    r = (r^lastans)%n+1;
    if (l > r) swap(l, r);
    lastans = count(l, r, add, add_pst)-count(l, r, del, del_pst);
    cout << lastans << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}