/*
 * @Author: Kaizyn
 * @Date: 2021-07-13 20:20:04
 * @LastEditTime: 2021-07-13 21:24:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, m;
// [L[i], R[i]] 第i个所在段的左右端点
int L[N], R[N];
ll t[N], val[N], buf[N], res[N], *sum = buf+1;
pli d[N], co[N];

inline ll calc(int i, ll d) {
#define l L[i]
#define r R[i]
  return (t[l]*2+(r-l)*d)*(r-l+1)/2-sum[r]+sum[l-1];
#undef l
#undef r
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    L[i] = R[i] = i;
    sum[i] = sum[i-1]+t[i];
    co[i] = pli{t[i]-t[i-1], i};
  }
  for (int i = 1; i <= m; ++i) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d+1, d+m+1);
  sort(co+1, co+n+1);
  ll time = 0;
  for (int i = 1, j = 1; i <= m; ++i) {
    time += (d[i].first-d[i-1].first)*(j-1);
    while (j <= n && co[j].first <= d[i].first) {
      int k = co[j].second, l = L[k-1], r = R[k];
      time -= calc(l, d[i].first)+calc(r, d[i].first);
      L[r] = l; R[l] = r;
      time += calc(l, d[i].first);
      ++j;
    }
    res[d[i].second] = time;
  }
  for (int i = 1; i <= m; ++i) cout << res[i] << '\n';
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