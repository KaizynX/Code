/*
 * @Author: Kaizyn
 * @Date: 2020-07-14 09:22:13
 * @LastEditTime: 2020-07-14 09:39:33
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 150000+7;
const int M = 40000+7;

int n, m;
int a[N], b[N];
int sa[N];
pii aa[N], bb[N];
bitset<M> s[M], cur;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    aa[i] = {a[i], i};
  }
  for (int i = 1; i <= m; ++i) {
    cin >> b[i];
    bb[i] = {b[i], i};
  }
  sort(aa+1, aa+n+1);
  sort(bb+1, bb+m+1);
  s[0].reset();
  for (int i = 1; i <= m; ++i) {
    s[i] = s[i-1];
    s[i].set(bb[i].second);
  }
  for (int i = 1, j = 1; i <= n; ++i) {
    while (j <= m && bb[j].first <= aa[i].first) ++j;
    sa[aa[i].second] = j-1;
  }
  int res = 0;
  for (int i = n; i; --i) {
    cur >>= 1;
    cur.set(m);
    cur &= s[sa[i]];
    res += cur[1];
  }
  cout << res << endl;
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