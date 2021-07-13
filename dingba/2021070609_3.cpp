/*
 * @Author: Kaizyn
 * @Date: 2021-07-13 23:37:34
 * @LastEditTime: 2021-07-13 23:39:02
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
ll t[N], dt[N], buf[N], res[N], *sum = buf+1;
pli d[N];
set<pli> co;

inline ll calc(int i, ll d) {
#define l L[i]
#define r R[i]
#ifdef DEBUG
  printf("calc(%d,%d,%lld)=%lld\n", l, r, d,
      (t[l]*2+(r-l)*d)*(r-l+1)/2-sum[r]+sum[l-1]);
#endif
  return (t[l]*2+(r-l)*d)*(r-l+1)/2-sum[r]+sum[l-1];
#undef l
#undef r
}

inline ll f(int x) {
  return x*(x-1ll)/2;
}

#ifdef DEBUG
void print(set<pli> &s) {
  for (auto &i : s) {
    printf("(%lld,%d) ", i.first, i.second);
  }
  putchar('\n');
}
#endif

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    L[i] = R[i] = i;
    sum[i] = sum[i-1]+t[i];
    dt[i] = t[i]-t[i-1];
    co.insert(pli{dt[i], i});
  }
  for (int i = 1; i <= m; ++i) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d+1, d+m+1);
  ll time = 0, tt = 0;
  for (int i = 1; i <= m; ++i) {
    time += (d[i].first-d[i-1].first)*tt;
    while (co.size() && co.begin()->first <= d[i].first) {
      int k = co.begin()->second, l = L[k-1], r = R[k];
      co.erase(co.begin());
      time -= calc(l, d[i].first)+calc(r, d[i].first);
      tt -= f(R[l]-l+1)+f(r-L[r]+1);
      L[r] = l; R[l] = r;
      time += calc(l, d[i].first);
      tt += f(r-l+1);
      if (r < n) {
        co.erase(pli{dt[r+1], r+1});
        dt[r+1] = (t[r+1]-t[l]+r-l)/(r-l+1);
        co.insert(pli{dt[r+1], r+1});
      }
#ifdef DEBUG
      print(co);
#endif
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
/*
4 3
0 1 6 8
5 7 9

35
55
75
*/