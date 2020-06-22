/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 20:58:04
 * @LastEditTime: 2020-06-13 21:59:52
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = (1<<18)+7;

struct Node {
  int v, w;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.w < rhs.w;
  }
};

int n, q;
int v[N], w[N];
int a[N], m;
int lg2[N];
// Node b[1<<9], c[1<<9];
int bv[1<<9], bw[1<<9], cv[1<<9], cw[1<<9], rk[1<<9];

inline int calc(const int &L) {
  int l = (m+1)/2, res = 0;
  bv[0] = bw[0] = rk[0] = 0;
  for (int i = 1, j, k; i < 1<<l; ++i) {
    j = i&-i;
    k = a[lg2[j]];
    rk[i] = i;
    bv[i] = bv[i^j]+v[k];
    bw[i] = bw[i^j]+w[k];
  }
  sort(rk, rk+(1<<l), [](const int &x, const int &y) {
      return bw[x] < bw[y];
  });
  for (int i = 1; i < 1<<l; ++i) {
    bv[i] = max(bv[i], bv[i-1]);
  }
  res = bv[upper_bound(bw, bw+(1<<l), L)-bw-1];
  cv[0] = cw[0] 0;
  for (int i = 1, j, k; i < 1<<(m-l); ++i) {
    j = i&-i;
    k = a[lg2[j]+l];
    c[i] = {c[i^j].v+v[k], c[i^j].w+w[k]};
    if (L < c[i].w) continue;
    // res = max(res, (upper_bound(b, b+(1<<l), Node{0, L-c[i].w})-1)->v+c[i].v);
    res = max(res, b[upper_bound(ww, ww+(1<<l), L-c[i].w)-ww-1].v+c[i].v);
  }
  return res;
}

inline void solve() {
  // cin >> n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    // cin >> v[i] >> w[i];
    scanf("%d %d", v+i, w+i);
  }
  // cin >> q;
  scanf("%d", &q);
  for (int i = 1, x, L; i <= q; ++i) {
    // cin >> x >> L;
    scanf("%d %d", &x, &L);
    m = 0;
    for (int j = x; j; j /= 2) a[m++] = j;
    // cout << calc(L) << endl;
    printf("%d\n", calc(L));
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i <= 18; ++i) lg2[1<<i] = i;
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}