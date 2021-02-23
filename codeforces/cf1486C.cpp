/*
 * @Author: Kaizyn
 * @Date: 2021-02-19 12:57:44
 * @LastEditTime: 2021-02-19 13:13:01
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

int n;

int query(int l, int r) {
  if (l > r) swap(l, r);
  cout << "? " << l << " " << r << endl;
  cin >> l;
  return l;
}

inline void solve() {
  cin >> n;
  int x = query(1, n), l, r, mid;
  if (x == n || (x != 1 && query(1, x) == x)) {
    l = 1, r = x-1;
    while (l < r) {
      mid = (l+r+1)>>1;
      if (query(x, mid) == x) l = mid;
      else r = mid-1;
    }
  } else {
    l = x+1, r = n;
    while (l < r) {
      mid = (l+r)>>1;
      if (query(x, mid) == x) r = mid;
      else l = mid+1;
    }
  }
  cout << "! " << l << endl;
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