/*
 * @Author: Kaizyn
 * @Date: 2021-02-19 13:18:13
 * @LastEditTime: 2021-02-19 13:25:02
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
const int N = 2e5+7;

int n, k;
int a[N];
multiset<int> ls, rs;

void magic() {
  while ((int)ls.size() > (k+1)/2) {
    rs.insert(*ls.rbegin());
    ls.erase(--ls.end());
  }
  while ((int)ls.size() < (k+1)/2) {
    ls.insert(*rs.begin());
    rs.erase(rs.begin());
  }
}

void insert(int x) {
  if (rs.size() && x >= *rs.begin()) {
    rs.insert(x);
  } else {
    ls.insert(x);
  }
}

void erase(int x) {
  if (ls.find(x) != ls.end()) {
    ls.erase(ls.find(x));
  } else {
    rs.erase(rs.find(x));
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) insert(a[i]);
  magic();
  int res = *ls.rbegin();
  for (int i = k+1; i <= n; ++i) {
    erase(a[i-k]);
    insert(a[i]);
    magic();
    res = max(res, *ls.rbegin());
  }
  cout << res << '\n';
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