/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 23:01:35
 * @LastEditTime: 2020-06-13 23:14:07
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

int n;
int a[N], b[N];
set<int> st;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  /*
  b[1] = a[1]^1;
  int u = a[1];
  for (int i = 2; i <= n; ++i) {
    if (a[i] == i) {
      b[i] = u;
      u = a[i];
    } else {
      b[i] = i;
    }
  }
  */
  for (int i = 0; i <= n; ++i) {
    st.insert(i);
  }
  a[0] = n+1;
  for (int i = n+1; i; --i) {
    if (st.find(a[i-1]) != st.end()) {
      st.erase(a[i-1]);
      b[i] = a[i-1];
    } else {
      b[i] = *st.rbegin();
      st.erase(--st.end());
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << b[i] << " \n"[i==n];
  }
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