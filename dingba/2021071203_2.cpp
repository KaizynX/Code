/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 14:27:50
 * @LastEditTime: 2021-07-12 14:36:39
 */
/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 14:09:28
 * @LastEditTime: 2021-07-12 14:25:53
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
const int N = 5e2+7;
const int dir[] = {0, -1, 0, 1, 0};

int n;
int p[N*N], a[N][N];
int cc[N], cs[N], rc[N], rs[N], cp[N], rp[N];
vector<int> e[N*N];

bool has(vector<int> &v, int x) {
  for (int &i : v) {
    if (i == x) return true;
  }
  return false;
}

inline void solve() {
  cin >> n;
  int start = 0;
  for (int i = 1, cnt; i <= n*n; ++i) {
    cin >> p[i];
    cin >> cnt;
    e[i].resize(cnt);
    for (int j = 0; j < cnt; ++j) cin >> e[i][j];
    if (cnt == 2) start = i;
  }
  a[1][1] = start;
  a[1][2] = e[start][0];
  // a[2][1] = e[start][1];
  for (int i = 2; i < n; ++i) {
    int nex = 0;
    for (int &j : e[a[1][i]]) {
      if (e[j].size() > 3u) continue;
      if (j != a[1][i-1]) nex = j;
    }
    a[1][i+1] = nex;
  }
  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int k : e[a[i-1][j]]) {
        int flag = 1;
        for (int d = 0, x, y; d < 4; ++d) {
          x = i-1+dir[d];
          y = j+dir[d+1];
          if (a[x][y] == k) {
            flag = 0;
            break;
          }
        }
        if (flag) {
          a[i][j] = k;
          break;
        }
      }
    }
  }
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << a[i][j] << " \n"[j==n];
    }
  }
#endif
  int min_val = INF, max_val = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) if (p[a[i][j]]) {
      rc[i] ++;
      rs[i] += j;
      rp[i] += j*j;
      cc[j] ++;
      cs[j] += i;
      cp[j] += i*i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) if (p[a[i][j]]) {
      int val = rp[i]+j*j*rc[i]-2*j*rs[i]+
                cp[j]+i*i*cc[j]-2*i*cs[j];
      min_val = min(min_val, val);
      max_val = max(max_val, val);
    }
  }
  cout << min_val << ' ' << max_val << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}