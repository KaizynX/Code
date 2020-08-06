/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 20:10:45
 * @LastEditTime: 2020-07-26 21:18:53
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

struct PersistenceSegmentTree {
  static const int NN = 30*N*(log2(30*N)+3);
  int rt[N], sum[NN], ls[NN], rs[NN], tot, sz, shit;
  void build(const int &n) {
    sz = n;
    tot = 0;
    rt[shit = 0] = _build(1, sz);
  }
  void update(const int &cur, const int &k, const int &v) {
    while (shit < cur) {
      rt[shit+1] = rt[shit];
      ++shit;
    }
    rt[cur] = _update(rt[cur], 1, sz, k, v);
  }
  // 查询区间内<=k的个数
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
  int _update(const int &pre, const int &l, const int &r, const int &k, const int &v) {
    int cur = ++tot;
    ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+v;
    if (l >= r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k, v);
    else rs[cur] = _update(rs[pre], mid+1, r, k, v);
    return cur;
  }
  int _query(const int &u, const int &v, const int &l, const int &r, const int &k) const {
    if (l >= r) return sum[v]-sum[u];
    int mid = (l+r)>>1;
    if (k <= mid) return _query(ls[u], ls[v], l, mid, k);
    else return _query(rs[u], rs[v], mid+1, r, k)+sum[ls[v]]-sum[ls[u]];
  }
};

struct Node {
  int l, r, v;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return pii{lhs.l, lhs.r} < pii{rhs.l, rhs.r};
  }
};

int n, q;
int a[N];
vector<Node> pr;
unordered_map<int, vector<pii>> mp;
PersistenceSegmentTree pst;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  mp.clear();
  // 对于每个不同的值找到最小的区间[i,j]
  for (int i = n; i; --i) {
    static vector<int> vec, b(30, n+1);
    for (int j = 29; j >= 0; --j) {
      if (~(a[i]>>j)&1) b[j] = i;
    }
    vec = b;
    sort(vec.begin(), vec.end());
    int val = a[i];
    mp[a[i]].emplace_back(i, i);
    for (const int &j : vec) {
      if (j > n) break;
      if ((val&a[j]) == val) continue;
      val &= a[j];
      mp[val].emplace_back(i, j);
    }
  }
  pr.clear();
  for (auto &mmp : mp) {
    static vector<int> que;
    vector<pii> &vec = mmp.second;
    sort(vec.begin(), vec.end());
    que.clear();
    // 去掉包含关系的区间
    for (int i = 0; i < (int)vec.size(); ++i) {
      while (que.size() && vec[que.back()].second >= vec[i].second) {
        que.pop_back();
      }
      que.push_back(i);
    }
    // 同一个值多个区间去重
    for (int i = 0; i < (int)que.size(); ++i) {
      pr.emplace_back(Node{vec[que[i]].first, vec[que[i]].second, 1});
      if (i) pr.emplace_back(Node{vec[que[i-1]].first, vec[que[i]].second, -1});
    }
  }
  sort(pr.begin(), pr.end());
  pst.build(n);
  for (const Node &nd : pr) pst.update(nd.l, nd.r, nd.v);
  #ifdef DEBUG
  for (const Node &nd : pr) printf("(%d,%d,%d)", nd.l, nd.r, nd.v);
  puts("");
  // int l, r, k;
  // while (cin >> l >> r >> k) cout << pst.query(l, r, k);
  #endif

  cin >> q;
  for (int i = 1, l, r, ans = 0; i <= q; ++i) {
    cin >> l >> r;
    l = (l^ans)%n+1;
    r = (r^ans)%n+1;
    if (l > r) swap(l, r);
    ans = pst.query(l, r, r);
    cout << ans << endl;
  }
  return 0;
}