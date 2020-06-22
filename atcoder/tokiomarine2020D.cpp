/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 20:58:04
 * @LastEditTime: 2020-06-13 22:05:00
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
Node b[1<<9], c[1<<9];

inline int calc(const int &L) {
  int l = (m+1)/2, res = 0;
  b[0] = {0, 0};
  for (int i = 1, j, k; i < 1<<l; ++i) {
    j = i&-i;
    k = a[lg2[j]];
    b[i] = {b[i^j].v+v[k], b[i^j].w+w[k]};
  }
  sort(b, b+(1<<l));
  for (int i = 1; i < 1<<l; ++i) {
    b[i].v = max(b[i].v, b[i-1].v);
  }
  res = (upper_bound(b, b+(1<<l), Node{0, L})-1)->v;
  c[0] = {0, 0};
  for (int i = 1, j, k; i < 1<<(m-l); ++i) {
    j = i&-i;
    k = a[lg2[j]+l];
    c[i] = {c[i^j].v+v[k], c[i^j].w+w[k]};
    if (L < c[i].w) continue;
    res = max(res, (upper_bound(b, b+(1<<l), Node{0, L-c[i].w})-1)->v+c[i].v);
  }
  return res;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> v[i] >> w[i];
  }
  cin >> q;
  for (int i = 1, x, L; i <= q; ++i) {
    cin >> x >> L;
    m = 0;
    for (int j = x; j; j /= 2) a[m++] = j;
    cout << calc(L) << endl;
    /*
    int res = 0;
    for (int r = 1, l = 1, sumv = 0, sumw = 0; r <= m; ++r) {
      sumw += w[a[r]];
      sumv += v[a[r]];
      while (sumw > L) {
        sumw -= w[a[l]];
        sumv -= v[a[l]];
        ++l;
      }
      res = max(res, sumv);
    }
    cout << res << endl;
    */
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for (int i = 0; i <= 18; ++i) lg2[1<<i] = i;
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}