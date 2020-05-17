/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 20:33:19
 * @LastEditTime: 2020-05-12 22:33:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, k;
int a[N], cntl[N], cntr[N];
set<int> stl, str;

inline void solve() {
  set<int>().swap(stl);
  set<int>().swap(str);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cntl[i] = cntl[i-1]+(a[i] < k);
    cntr[i] = cntl[i-1]+(a[i] > k);
  }
  stl.insert(0);
  str.insert(0);
  for (int i = 1; i <= n; ++i) {
    auto pl = stl.upper_bound(2*cntl[i]-i+1);
    auto pr = str.upper_bound(2*cntr[i]-i);
    if (pl != stl.end() && pr != str.end()) {
      return void(cout << "yes" << endl);
    }
    stl.insert(2*cntl[i]-i);
    str.insert(2*cntr[i]-i);
  }
  cout << "no" << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}