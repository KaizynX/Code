/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 23:01:13
 * @LastEditTime: 2021-07-17 23:22:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n;
int a[N], b[N];
set<int> st, st2;

inline void solve() {
  st.clear();
  st2.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = 0;
    st.insert(i);
  }
  int k = 0;
  for (int i = 1; i <= n; ++i) {
    if (st.count(a[i])) {
      st.erase(a[i]);
      b[i] = a[i];
      ++k;
    }
  }
  // fuck?
  if (st.size() == 1 && !b[*st.begin()]) {
    for (int i = n; i; --i) {
      if (b[i]) continue;
      for (int j = i-1; j; --j) {
        if (a[j] == a[i] && b[j]) {
          b[j] = 0;
          b[i] = a[i];
          break;
        }
      }
      break;
    }
  }
  // fuck!
  for (int i = 1; i <= n; ++i) {
    if (!b[i] && st.count(i)) {
      st.erase(i);
      st2.insert(i);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (b[i]) continue;
    if (st2.size()) {
      auto it = st2.upper_bound(i);
      if (it == st2.end()) it = st2.begin();
      if (*it != i) {
        b[i] = *it;
        st2.erase(it);
        continue;
      }
    }
    auto it = st.begin();
    b[i] = *it;
    st.erase(it);
  }
  cout << k << '\n';
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << " \n"[i==n];
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1
5
3 1 1 2 1
*/