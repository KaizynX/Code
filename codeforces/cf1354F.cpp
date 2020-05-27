/*
 * @Author: Kaizyn
 * @Date: 2020-05-18 21:32:35
 * @LastEditTime: 2020-05-18 22:35:41
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 80;

struct Node {
  int a, b, id;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.b < rhs.b;
  }
  friend istream& operator >>(istream &is, Node &nd) {
    return is >> nd.a >> nd.b;
  }
};

int n, k;
Node c[N], d[N];
int dp[N][N], val[N], vis[N];
vector<int> seq;
// dp[i][j] choose j's [1, i]
// val[i] the val choose i as last

inline int work() {
  memcpy(d+1, c+1, sizeof(Node)*n);
  sort(d+1, d+n);
  fill(dp[0], dp[0]+n*N, -INF);
  dp[0][0] = 0;
  for (int i = 1; i < n; ++i) {
    memcpy(dp[i], dp[i-1], sizeof(int)*k);
    for (int j = 1; j < k; ++j) {
      dp[i][j] = max(dp[i][j], dp[i-1][j-1]+d[i].a-d[i].b*(k-j));
    }
  }
  return dp[n-1][k-1]+d[n].a;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> c[i], c[i].id = i;

  int last = 1;
  for (int i = 1; i <= n; ++i) {
    // choose c[i] as last
    swap(c[i], c[n]);
    val[i] = work();
    if (val[i] > val[last]) last = i;
    swap(c[i], c[n]);
  }

  swap(c[last], c[n]);
  work();
  vector<int>().swap(seq);
  memset(vis+1, 0, sizeof(int)*n);
  vis[d[n].id] = 1;
  for (int i = n-1, j = k-1; i && j; --i) {
    if (dp[i][j] == dp[i-1][j-1]+d[i].a-d[i].b*(k-j)) {
      vis[d[i].id] = 1;
      seq.emplace_back(d[i].id);
      --j;
    }
  }
  reverse(seq.begin(), seq.end());
  cout << 2*n-k << endl;
  for (auto &i : seq) cout << i << " ";
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    cout << i << " " << -i << " ";
  }
  cout << d[n].id << endl;
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) val[last] += c[i].b*(k-1);
  cout << "val = " << val[last] << endl;
#endif
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