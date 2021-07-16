/*
 * @Author: Kaizyn
 * @Date: 2021-07-16 15:35:36
 * @LastEditTime: 2021-07-16 16:53:16
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
const int P = 1572869;
// const int P = 299987;
const int M = 1<<21;
const int N = 17;

int n, m;
int a[N][N];
long long dp[2][M];
int head[2][P], nex[2][M], tot[2], ver[2][M];
// long long dp[2][P];
// int head[2][P], nex[2][P], tot[2], ver[2][P];

inline void clear(const int &u) {
  for (int i = 1; i <= tot[u]; ++i) {
    dp[u][i] = 0; //
    nex[u][i] = 0; //
    head[u][ver[u][i]%P] = 0;
  }
  tot[u] = 0;
}

template <typename T, typename U>
inline void insert(const int &u, const T &x, const U &v) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i] += v, void();
  }
  ++tot[u]; assert(tot[u] < M);
  ver[u][tot[u]] = x;
  nex[u][tot[u]] = head[u][p];
  head[u][p] = tot[u];
  dp[u][tot[u]] = v;
}

template <typename T>
inline int get_val(const int &u, const T &x) {
  int p = x%P;
  for (int i = head[u][p]; i; i = nex[u][i]) {
    if (ver[u][i] == x) return dp[u][i];
  }
  return 0;
}

inline long long solve() {
  cin >> n >> m;
  memset(a, -1, sizeof a);
  for (int i = 2; i <= n; ++i) {
    static string str;
    cin >> str;
    for (int j = 2; j <= m; ++j) {
      if (str[j-2] == '.') a[i][j] = -1;
      else a[i][j] = str[j-2]-'0';
    }
  }
  int u = 0;
  ll base = (1ll<<m*2+2)-1;
  clear(u);
  insert(u, 0, 1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      clear(u ^= 1);
      for (int k = 1; k <= tot[u^1]; ++k) {
        ll state = ver[u^1][k];
        ll val = dp[u^1][k];
        if (j == 1) state = (state<<2)&base;
        // b1 right b2 down
        // low ritht, high down
        ll bb1 = (state>>j*2-2)%4, bb2 = (state>>j*2)%4, bb3 = (state>>j*2+2)%4;
        ll b1 = bb1%2, b2 = bb3/2;
        int cnt = (bb2%2 != 0)+(bb2/2 != 0)+(b1 != 0)+(b2 != 0);
        if (~a[i][j] && cnt%2 != a[i][j]) continue;
        state ^= bb2<<j*2;
        if (!b1 && !b2) {
          insert(u, state, val);
          if (i < n && j < m) insert(u, state|(3ll<<j*2), val);
        } else if (!b1 && b2) {
          if (j < m) insert(u, state|(b2<<j*2), val);
          if (i < n) insert(u, state|(b2*2<<j*2), val);
        } else if (b1 && !b2) {
          if (i < n) insert(u, state|(b1<<j*2), val);
          if (j < m) insert(u, state|(b1*2<<j*2), val);
        } else {
          insert(u, state, val);
          if (i < n && j < m) insert(u, state|(3ll<<j*2), val);
        }
      }
    }
  }
  long long res = 0;
  for (int k = 1; k <= tot[u]; ++k) {
    res += dp[u][k];
  }
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}