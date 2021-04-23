/*
 * @Author: Kaizyn
 * @Date: 2021-04-22 13:56:39
 * @LastEditTime: 2021-04-22 15:05:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
const int C = 2e3+7;

struct Rec {
  int yl, yr, id;
};

int mnt[C][C], mxt[C][C];

void Erase(set<int> &st, int x) {
  auto it = st.find(x);
  if (it != st.end()) st.erase(it);
}

struct SegmentTree {
  struct TreeNode {
    int l, r;
    // priority_queue<pii, vector<pii>, greater<pii>> ql;
    // priority_queue<pii, vector<pii>, less<pii>> qr;
    set<int> st;
  } tr[C<<2];
  set<int> stt;
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    if (l == r) return;
    int mid = (l+r)/2;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int l, int r, int k, int op = 0, int i = 1) {
    if (tr[i].l <= l && tr[i].r >= r) {
      if (op) tr[i].st.insert(k);
      else tr[i].st.erase(k);
      return;
    }
    int mid = (tr[i].l+tr[i].r)/2;
    if (l <= mid) update(l, r, k, i<<1);
    if (r >  mid) update(l, r, k, i<<1|1);
  }
  void dfs(int x, int i = 1) {
    if (tr[i].st.size()) {
      stt.insert(*(tr[i].st.begin()));
      stt.insert(*(tr[i].st.rbegin()));
    }
    if (tr[i].l == tr[i].r) {
      if (stt.size()) {
        mnt[x][tr[i].l] = *stt.begin();
        mxt[x][tr[i].l] = *stt.rbegin();
      }
    } else {
      dfs(x, i<<1);
      dfs(x, i<<1|1);
    }
    if (tr[i].st.size()) {
      Erase(stt, *(tr[i].st.begin()));
      Erase(stt, *(tr[i].st.rbegin()));
    }
  }
};

int n, q;
vector<Rec> add[C], del[C];
SegmentTree tree;

inline void solve() {
  cin >> n >> q;
  for (int i = 1, xl, xr; i <= n; ++i) {
    static Rec tmp;
    tmp.id = i;
    cin >> xl >> tmp.yl >> xr >> tmp.yr;
    add[xl].emplace_back(tmp);
    del[xr+1].emplace_back(tmp);
  }
  for (int i = 1; i <= n; ++i) {
    for (auto &a : add[i]) {
      tree.update(a.yl, a.yr, a.id, 1);
    }
    for (auto &a : del[i]) {
      tree.update(a.yl, a.yr, a.id, 0);
    }
    tree.dfs(i);
  }
  for (int i = 1, s, t; i <= q; ++i) {
    cin >> s >> t;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}