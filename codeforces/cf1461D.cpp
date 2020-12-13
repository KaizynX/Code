/*
 * @Author: Kaizyn
 * @Date: 2020-12-11 22:32:58
 * @LastEditTime: 2020-12-11 22:49:40
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

int n, q;
int a[N], b[N];
long long sum[N];
set<pii> st;
set<long long> mp;

void f(int l, int r) {
  if (l < r) {
    int m = (l+r)>>1;
    auto it = st.upper_bound({m, n});
    if (it != st.end()) f(it->first, r);
    if (it != st.begin()) f(l, (--it)->first);
  }
  int lp = st.lower_bound({l, 0})->second,
      rp = (--st.upper_bound({r, n}))->second;
  mp.insert(sum[rp]-sum[lp-1]);
}

inline void solve() {
  st.clear();
  mp.clear();
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1]+a[i];
    st.insert({a[i], i});
  }
  f(st.begin()->first, st.rbegin()->first);
  for (int _ = q, s; _; --_) {
    cin >> s;
    cout << (mp.count(s) ? "YES" : "NO") << endl;
  }
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