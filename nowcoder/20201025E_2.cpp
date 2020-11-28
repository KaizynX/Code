/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 15:02:01
 * @LastEditTime: 2020-10-25 16:24:50
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
int a[N];
vector<int> p[N];

int mx[N << 2], se[N << 2], cn[N << 2], tag[N << 2];
inline void pushup(int u) {  // 向上更新标记
  const int ls = u << 1, rs = u << 1 | 1;
  if (mx[ls] == mx[rs]) {
    mx[u] = mx[rs];
    se[u] = min(se[ls], se[rs]);
    cn[u] = cn[ls] + cn[rs];
  } else if (mx[ls] < mx[rs]) {
    mx[u] = mx[ls];
    se[u] = min(se[ls], mx[rs]);
    cn[u] = cn[ls];
  } else {
    mx[u] = mx[rs];
    se[u] = min(mx[ls], se[rs]);
    cn[u] = cn[rs];
  }
}
inline void pushtag(int u, int tg) {  // 单纯地打标记，不暴搜
  if (mx[u] >= tg) return;
  mx[u] = tag[u] = tg;
}
inline void pushdown(int u) {
  if (tag[u] == -1) return;
  pushtag(u << 1, tag[u]), pushtag(u << 1 | 1, tag[u]);
  tag[u] = -1;
}
void build(int u = 1, int l = 1, int r = n) {
  tag[u] = -1;
  if (l == r) {
    mx[u] = 0, se[u] = INF, cn[u] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
void modify_max(int L, int R, int v, int u = 1, int l = 1, int r = n) {
  if (mx[u] >= v) return;
  if (L <= l && r <= R && se[u] < v) return pushtag(u, v);
  int mid = (l + r) >> 1;
  pushdown(u);
  if (L <= mid) modify_max(L, R, v, u << 1, l, mid);
  if (mid < R) modify_max(L, R, v, u << 1 | 1, mid + 1, r);
  pushup(u);
}
int query_min(int L, int R, int u = 1, int l = 1, int r = n) {
  if (L <= l && r <= R) return mx[u];
  int mid = (l + r) >> 1, r1 = INF, r2 = INF;
  pushdown(u);
  if (L <= mid) r1 = query_min(L, R, u << 1, l, mid);
  if (mid < R) r2 = query_min(L, R, u << 1 | 1, mid + 1, r);
  return min(r1, r2);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) p[i].emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  build();
  for (int i = 1; i <= m; ++i) {
    for (int j = 1; j < (int)p[i].size(); ++j)
      modify_max(p[i][j-1]+1, p[i][j], p[i][j]);
    if (p[i].back() < n)
      modify_max(p[i].back()+1, n, INF);
    cout << query_min(1, n)+1 << " \n"[i==m];
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