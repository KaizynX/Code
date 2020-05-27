/*
 * @Author: Kaizyn
 * @Date: 2020-05-26 22:28:11
 * @LastEditTime: 2020-05-26 23:36:02
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e5+7;

int n;
int d[N];
long long pre_cnt[N], pre_sum[N];
long long x;

inline long long suf_sum(const int &i, const long long &l) {
  return (d[i]-l+1ll+d[i])*l/2;
}

inline void solve() {
  cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    d[i+n] = d[i];
  }
  for (int i = 1; i <= 2*n; ++i) {
    pre_cnt[i] = pre_cnt[i-1]+d[i];
    pre_sum[i] = pre_sum[i-1]+(1ll+d[i])*d[i]/2;
  }
  #ifdef DEBUG
  for (int i = 1; i <= 2*n; ++i) cout << pre_cnt[i] << " \n"[i==2*n];
  for (int i = 1; i <= 2*n; ++i) cout << pre_sum[i] << " \n"[i==2*n];
  #endif
  long long res = 0;
  for (int i = n+1; i <= 2*n; ++i) {
    // end at d[i]'s end
    int l = 0, r = i, mid;
    while (l < r) {
      mid = (l+r)>>1;
      if (pre_cnt[i]-pre_cnt[mid] <= x) r = mid;
      else l = mid+1;
    }
    #ifdef DEBUG
    cout << i << " " << l << endl;
    #endif
    res = max(res, pre_sum[i]-pre_sum[l]+suf_sum(l, x-(pre_cnt[i]-pre_cnt[l])));
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