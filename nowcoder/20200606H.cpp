/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 14:14:10
 * @LastEditTime: 2020-06-06 14:20:48
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;
const int M = 2e3+7;

int n, m;
int w[N];
int cnt[32];

inline void solve() {
  cin >> n >> m;
  memset(cnt, 0, sizeof cnt);
  long long res = 0, sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    if (w[i] != -1) sum += w[i];
  }
  int nei = 0;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    if (w[v] == -1) swap(u, v);
    if (w[u] == -1) {
      ++nei;
      for (int j = 0; j < 31; ++j) {
        cnt[j] += (w[v]>>j)&1;
      }
    } else {
      res += w[u]^w[v];
    }
  }
  int val = 0;
  for (int j = 0; j < 31; ++j) {
    if (nei-cnt[j] >= cnt[j]) {
      res += (1ll<<j)*cnt[j];
    } else {
      val += 1<<j;
      res += (1ll<<j)*(nei-cnt[j]);
    }
  }
  cout << res << endl;
  cout << sum+val << endl;
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