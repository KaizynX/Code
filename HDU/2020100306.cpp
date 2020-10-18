/*
 * @Author: Kaizyn
 * @Date: 2020-10-04 09:25:50
 * @LastEditTime: 2020-10-04 10:16:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 20;
const int K = 5;
const int M = 1e2;

int n, m, goal;
int p[N], op[N], k[N];
int b[N][K], c[N][K];
int q[M], t[M];
int d[M][K], e[N][K];
int gem[K], chips[K];

int calc() {
  sort(chips, chips+K);
  reverse(chips, chips+K);
  int sum = 0, res = INF;
  for (int i = 0; i < K; ++i) sum += chips[i];
  int l = 0, r = sum/3;
  while (l < r) {
    int mid = (l+r)>>1;
    if ();
  }
  for (int i = 0; i; ++i) {
    res = min(res, (sum+2)/3);
  }
  return res;
}

inline void solve() {
  cin >> n >> m >> goal;
  for (int i = 0; i < n; ++i) {
    cin >> p[i] >> op[i] >> k[i];
    for (int j = 0; j < k[i]; ++j) {
      cin >> b[i][j] >> c[i][j];
      --b[i][j];
    }
  }
  for (int i = 0; i < m; ++i) {
    cin >> q[i] >> t[i];
    for (int j = 0; j < t[i]; ++j) {
      cin >> d[i][j] >> e[i][j];
      --d[i][j];
    }
  }
  int res = -1;
  for (int bit = 0, turn, score; bit < 1<<n; ++bit) {
    turn = score = 0;
    memset(gem, 0, sizeof gem);
    memset(chips, 0, sizeof chips);
    for (int i = 0; i < n; ++i) if ((bit>>i)&1) {
      ++gem[op[i]];
      ++turn;
      score += p[i];
      for (int j = 0; j < k[i]; ++j) {
        chips[b[i][j]] += c[i][j];
      }
    }
    for (int i = 0, flag; i < m; ++i) {
      flag = 1;
      for (int j = 0; j < t[i]; ++j) {
        if (gem[d[i][j]] < e[i][j]) flag = 0;
      }
      if (flag) score += q[i];
    }
    if (score < goal) continue;
    turn += calc();
    res = ~res ? min(res, turn) : turn;
  }
  cout << res << endl;
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