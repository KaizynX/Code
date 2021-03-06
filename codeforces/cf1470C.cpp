/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 22:32:35
 * @LastEditTime: 2021-01-09 19:51:03
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, k;
ll buf[2][N], *a[2] = {buf[0]+N/2, buf[1]+N/2};

int query(int x) {
  cout << "? " << x << endl;
  cin >> x;
  return x;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 0; i <= 31; ++i) {
    a[0][i] = a[0][-i] = k;
    a[1][i] = a[1][-i] = k;
  }
  for (int i = 1; i <= 30; ++i) {
    query(1);
    ll *cur = a[i&1], *pre = a[~i&1];
    cur[0] = (pre[-1]+1)/2+pre[1]/2;
    cur[1] = pre[0]+pre[2]/2;
    cur[-1] = (pre[-2]+1)/2;
    for (int j = 2; j <= i; ++j) {
      cur[j] = (pre[j-1]+1)/2+pre[j+1]/2;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}