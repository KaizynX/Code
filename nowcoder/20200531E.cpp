/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 14:13:00
 * @LastEditTime: 2020-05-31 14:42:50
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n;
int a[N];
multiset<int> st;

inline void solve() {
  multiset<int>().swap(st);
  cin >> n;
  for (int i = 1, b; i <= n; ++i) {
    cin >> b;
    st.insert(b);
  }
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    auto it = st.upper_bound(a[i]);
    if (it == st.end()) continue;
    st.erase(it);
    ++res;
  }
  cout << res << endl;
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