/*
 * @Author: Kaizyn
 * @Date: 2020-12-17 13:26:06
 * @LastEditTime: 2020-12-17 16:34:04
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
const int N = 10;
const int M = 50;

struct Node {
  int l, r;
  ll s;
  bool operator <(const Node &b) const {
    return s > b.s;
  }
};

int n;
int a[N];
vector<Node> seg;
map<vector<int>, ll> dp[M];

#ifdef DEBUG
void print(int i, const vector<int> &v) {
  printf("dp[%d][(", i);
  for (const int &a : v) printf("%d,", a);
  printf(")]=%lld\n", dp[i][v]);
}
#endif

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m = n*(n+1)/2;
  ll all = 0;
  for (int l = 0; l < n; ++l) {
    ll s = 0;
    for (int r = l; r < n; ++r) {
      seg.emplace_back(Node{l, r, s += a[r]});
      all += s;
    }
  }
  sort(seg.begin(), seg.end());
  dp[0][vector<int>(n, n-1)] = 0;
  for (int i = 0, l, r; i < m; ++i) {
    l = seg[i].l;
    r = seg[i].r;
    ll s = seg[i].s;
    #ifdef DEBUG
    printf("seg(%d,%d,%lld)\n", l, r, s);
    #endif
    for (int j = i+1; j; --j) {
      for (const auto &pr : dp[j-1]) {
        auto state = pr.first;
        ll val = pr.second;
        for (int k = 0; k <= l; ++k) if (state[k] >= r) {
          val += s*(state[k]-r+1);
          state[k] = r-1;
        }
        dp[j][state] = max(dp[j][state], val);
        #ifdef DEBUG
        print(j, state);
        #endif
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    ll mx = 0;
    for (const auto &pr : dp[i]) mx = max(mx, pr.second);
    cout << all-mx << endl;
  }
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}