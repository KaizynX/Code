/*
 * @Author: Kaizyn
 * @Date: 2021-02-20 19:08:16
 * @LastEditTime: 2021-02-20 19:19:39
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
const int N = 5e5+7;

int n, m, res1, res2;
vector<int> a[N];
multiset<int> s1, s2;

void update1(int p, int x) {
  if (p < n) {
    s1.erase(s1.find(abs(a[p].back()-a[p+1].front())));
    s1.insert(abs(x-a[p+1].front()));
  }
  s1.insert(abs(a[p].back()-x));
  a[p].emplace_back(x);
  res1 = *s1.begin();
}

void update2(int x) {
  auto it = s2.lower_bound(x);
  if (it != s2.end()) res2 = min(res2, *it-x);
  if (it != s2.begin()) res2 = min(res2, x-*(--it));
  s2.insert(x);
}

inline void solve() {
  cin >> n >> m;
  res1 = res2 = 2e9;
  for (int i = 1; i <= n; ++i) {
    a[i].resize(1);
    cin >> a[i][0];
    if (i > 1) s1.insert(abs(a[i][0]-a[i-1][0]));
    update2(a[i][0]);
  }
  res1 = *s1.begin();
  for (int _ = m, p, x; _; --_) {
    static string str;
    cin >> str;
    if (str == "insert") {
      cin >> p >> x;
      update1(p, x);
      update2(x);
    } else if (str == "query_1") {
      cout << res1 << '\n';
    } else {
      cout << res2 << '\n';
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