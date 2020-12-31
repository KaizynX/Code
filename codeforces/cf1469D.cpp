/*
 * @Author: Kaizyn
 * @Date: 2020-12-28 22:30:05
 * @LastEditTime: 2020-12-28 23:37:54
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

int n;
int vis[N];
vector<pii> res;

void print() {
  assert((int)res.size() <= n+5);
  cout << res.size() << endl;
  for (auto &p : res) cout << p.first << " " << p.second << endl;
}

inline void solve() {
  cin >> n;
  res.clear();
  memset(vis+1, 0, sizeof(int)*n);
  vis[1] = vis[2] = vis[n] = 1;
  int i = n;
  for (int j; (j = sqrt(i)) > 2; ) {
    res.emplace_back(n, j);
    i = (i+j-1)/j;
    vis[j] = 1;
    res.emplace_back(j, n);
  }
  while (i > 1) res.emplace_back(n, 2), i = (i+1)/2;
  reverse(res.begin(), res.end());
  for (int i = n; i; --i) {
    if (!vis[i]) res.emplace_back(i, n);
  }
  reverse(res.begin(), res.end());
  print();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}