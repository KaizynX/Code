/*
 * @Author: Kaizyn
 * @Date: 2020-10-17 21:32:42
 * @LastEditTime: 2020-10-17 22:25:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, k;
int a[N], c[N];
set<pli> st;

long long calc(int x, int t) {
  int one = x/t, cnt = x%t;
  return (one+1ll)*(one+1ll)*cnt+1ll*one*one*(t-cnt);
}

inline void solve() {
  cin >> n >> k;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    c[i] = 1;
    res += calc(a[i], 1);
    if (a[i] > 1) st.insert({calc(a[i], 2)-calc(a[i], 1), i});
  }
  for (int _ = k-n; _; --_) {
    auto it = st.begin();
    int id = it->second;
    res += it->first;
    st.erase(it);
    if (++c[id] >= a[id]) continue;
    st.insert({calc(a[id], c[id]+1)-calc(a[id], c[id]), id});
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