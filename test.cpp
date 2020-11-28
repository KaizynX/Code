#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct SegmentTree {
  struct TreeNode {
    int l, r, v;
  } tr[N<<3];
  int mv(int x, int y) { return min(x, y); }
  void build(int l, int r, int i = 1) {
    tr[i] = TreeNode{l, r, INT_MAX};
    if (l == r) return;
    int m = (l+r)>>1;
    build(l, m, i<<1);
    build(m+1, r, i<<1|1);
  }
  void update(int x, int k, int i = 1) {
    if (tr[i].l == tr[i].r) return tr[i].v = mv(tr[i].v, k), void();
    int m = (tr[i].l+tr[i].r)>>1;
    if (x <= m) { update(x, k, i<<1); }
    else { update(x, k, i<<1|1); }
    tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v);
  }
  int query(int l, int r, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
    int m = (tr[i].l+tr[i].r)>>1;
    if (r <= m) return query(l, r, i<<1);
    if (l >  m) return query(l, r, i<<1|1);
    return mv(query(l, r, i<<1), query(l, r, i<<1|1));
  }
};

struct Node {
  int x, y;
  bool operator <(const Node &nex) const {
    return x < nex.x;
  }
};

int n, m;
vector<int> dx, dy;
vector<long long> dis;
vector<Node> user, delv;
SegmentTree tree1, tree2;

void discrete() {
#define lwb(x, y) y=lower_bound(x.begin(),x.end(), y)-x.begin()
  dx.resize(n+m);
  for (int i = 0; i < n; ++i) dx[i] = user[i].x;
  for (int i = 0; i < m; ++i) dx[i+n] = delv[i].x;
  sort(dx.begin(), dx.end());
  dx.resize(unique(dx.begin(), dx.end())-dx.begin());
  for (int i = 0; i < n; ++i) lwb(dx, user[i].x);
  for (int i = 0; i < m; ++i) lwb(dx, delv[i].x);

  dy.resize(n+m);
  for (int i = 0; i < n; ++i) dy[i] = user[i].y;
  for (int i = 0; i < m; ++i) dy[i+n] = delv[i].y;
  sort(dy.begin(), dy.end());
  dy.resize(unique(dy.begin(), dy.end())-dy.begin());
  for (int i = 0; i < n; ++i) lwb(dy, user[i].y);
  for (int i = 0; i < m; ++i) lwb(dy, delv[i].y);
#undef lwb
}

void calc_max_dis() {
  int sz_y = dy.size(), sz_x = dx.size();
  dis = vector<long long>(n, INT_MAX);
  sort(user.begin(), user.end());
  sort(delv.begin(), delv.end());
  tree1.build(0, sz_y-1);
  tree2.build(0, sz_y-1);
  for (int x = 0, ui = 0, di = 0, y; x < sz_x; ++x) {
    while (di < m && delv[di].x == x) {
      y = delv[di].y;
      tree1.update(y, -dx[x]-dy[y]);
      tree2.update(y, -dx[x]+dy[y]);
      ++di;
    }
    while (ui < n && user[ui].x == x) {
      y = user[ui].y;
      dis[ui] = min({dis[ui],
          0ll+dx[x]+dy[y]+tree1.query(0, y),
          0ll+dx[x]-dy[y]+tree2.query(y, sz_y-1)});
      ++ui;
    }
  }

  tree1.build(0, sz_y-1);
  tree2.build(0, sz_y-1);
  for (int x = sz_x-1, ui = n-1, di = m-1, y; x >= 0; --x) {
    while (di >= 0 && delv[di].x == x) {
      y = delv[di].y;
      tree1.update(y, +dx[x]-dy[y]);
      tree2.update(y, +dx[x]+dy[y]);
      --di;
    }
    while (ui >= 0 && user[ui].x == x) {
      y = user[ui].y;
      dis[ui] = min({dis[ui],
          0ll-dx[x]+dy[y]+tree1.query(0, y),
          0ll-dx[x]-dy[y]+tree2.query(y, sz_y-1)});
      --ui;
    }
  }
}

bool check(int mid) {
  int cnt = 0,
      minx = INT_MAX, miny = INT_MAX, 
      maxx = INT_MIN, maxy = INT_MIN;
  for (int i = 0, x, y; i < n; ++i) if (dis[i] > mid) {
    ++cnt;
    x = dx[user[i].x]+dy[user[i].y];
    y = dx[user[i].x]-dy[user[i].y];
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y);
  }
  if (!cnt) return true;
  int mxd = INT_MAX,
      qx = (0ll+minx+maxx)/2,
      qy = (0ll+miny+maxy)/2;
  for (int x = qx; x <= qx; ++x) {
    for (int y = qy; y <= qy; ++y) {
      if ((x+y)%2 != 0) continue;
      mxd = min(mxd, max({
          abs(x-minx),
          abs(x-maxx),
          abs(y-miny),
          abs(y-maxy)}));
    }
  }
  return mxd <= mid;
}

inline void solve() {
  user.resize(n);
  delv.resize(m);
  for (int i = 0; i < n; ++i) cin >> user[i].x >> user[i].y;
  for (int i = 0; i < m; ++i) cin >> delv[i].x >> delv[i].y;
  discrete();
  calc_max_dis();
  int l = 0, r = 2e9;
  while (l < r) {
    int mid = (l+r+0ll)>>1;
    if (check(mid)) { r = mid; }
    else { l = mid+1; }
  }
  cout << l << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) solve();
  return 0;
}