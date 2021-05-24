/*
 * @Author: Kaizyn
 * @Date: 2021-05-08 19:07:43
 * @LastEditTime: 2021-05-08 19:12:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;

int n, w;
int a[N];
multiset<int> st;

inline int f() {
  int f1 = *st.rbegin();
  st.erase(st.find(f1));
  int f2 = *st.rbegin();
  st.erase(st.find(f2));
  int f3 = *st.rbegin();
  st.insert(f1);
  st.insert(f2);
  return f3;
}

inline void solve() {
  st.clear();
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i < w; ++i) st.insert(a[i]);
  for (int i = w; i <= n; ++i) {
    st.insert(a[i]);
    cout << f() << " \n"[i==n];
    st.erase(st.find(a[i-w+1]));
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (cin >> n >> w) solve();
  return 0;
}