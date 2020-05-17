/*
 * @Author: Kaizyn
 * @Date: 2020-05-09 13:26:29
 * @LastEditTime: 2020-05-09 14:02:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e4+7;
const int NN = sqrt(N)+.5;

int n, m, k, t;
int a[N], mem[N<<2], *cnt = mem+(N<<1);
int sum[NN][N];
vector<int> pos[N];

inline void build() {
  for (int i = 0; i < (n+t-1)/t; ++i) {
    for (int j = t*i; j < t*i+t; ++j) ++cnt[a[j]];
    for (int j = 0; j < n; ++j) sum[i][j+1] = sum[i][j]+cnt[k-a[j]];
    for (int j = t*i; j < t*i+t; ++j) --cnt[a[j]];
  }
}

inline int calc(const int &v, const int &l, const int &r) {
  if (v < 1 || v > n) return 0;
  return upper_bound(pos[v].begin(), pos[v].end(), r)-
      lower_bound(pos[v].begin(), pos[v].end(), l);
}

inline int query(const int &l, const int &r, const int &u, const int &v) {
    int res = 0, i = l;
    for ( ; i <= r && i%t; ++i) res += calc(k-a[i], u, v);
    for ( ; i+t-1 <= r; i += t) res += sum[i/t][v+1]-sum[i/t][u];
    for ( ; i <= r; ++i) res += calc(k-a[i], u, v);
    return res;
}

inline void solve() {
  t = static_cast<int>(sqrt(n)+.5);
  for (int i = 0; i < n; ++i) cin >> a[i], pos[a[i]].emplace_back(i);
  build();
  cin >> m;
  for (int t = 1, l, r, u, v; t <= m; ++t) {
    cin >> l >> r >> u >> v;
    cout << query(--l, --r, --u, --v) << endl;
  }
  for (int i = 1; i <= N; ++i) vector<int>().swap(pos[i]);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> k) solve();
  return 0;
}