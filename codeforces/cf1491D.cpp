/*
 * @Author: Kaizyn
 * @Date: 2021-02-28 22:11:11
 * @LastEditTime: 2021-02-28 23:10:01
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
const int N = 1e3+7;

struct DSU {
  int fa[N];
  void init(int n) { iota(fa, fa+n+1, 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};

int magic[2][2][3];
int vis[N];
DSU dsu;

/*
inline bool solve(int u, int v) {
  int j = 0;
  for (int i = 0; i < 30; ++i) {
    j = magic[(u>>i)&1][(v>>i)&1][j];
    if (j == -1) return false;
  }
  return j != 1;
}
*/
vector<int> vu, vv;

inline bool solve(int u, int v) {
  if (u > v) return false;
  vu.clear();
  vv.clear();
  for (int i = 0; i < 30; ++i) {
    if ((u>>i)&1) vu.emplace_back(i);
    if ((v>>i)&1) vv.emplace_back(i);
  }
  while (vv.size()) {
    while (vu.size() && vu.back() > vv.back()) vu.pop_back();
    if (vu.size()) vu.pop_back(), vv.pop_back();
    else return false;
  }
  return true;
}


void fuck(int x) {
  queue<int> q;
  q.push(x);
  vis[x] = 1;
  while (q.size()) {
    int i = q.front();
    q.pop();
    for (int j = 1; j <= i && i+j <= 1000; ++j) {
      if ((i&j) == j) {
        if (!vis[i+j]) {
          vis[i+j] = 1;
          q.push(i+j);
        }
      }
    }
  }
}

void brute() {
  dsu.init(1000);
  for (int i = 1; i <= 1000; ++i) {
    memset(vis, 0, sizeof vis);
    fuck(i);
    cout << i << ": ";
    for (int j = i; j <= 1000; ++j) {
      if (solve(i, j) != vis[j]) {
        cout << "error:" << i << ' ' << j << "ans:" << vis[j] << '\n';
      }
      /*
      // if (vis[j]) cout << j << " ";
      if ((__builtin_popcount(i) >= __builtin_popcount(j)) != vis[j]) {
        cout << j << " ";
      }
      */
    }
    cout << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  magic[0][0][0] = 0;
  magic[0][0][1] = 1;
  magic[0][0][2] = 2;
  magic[0][1][0] = -1;
  magic[0][1][1] = 0;
  magic[0][1][2] = 0;
  magic[1][0][0] = 1;
  magic[1][0][1] = 1;
  magic[1][0][2] = 1;
  magic[1][1][0] = 0;
  magic[1][1][1] = 1;
  magic[1][1][2] = 2;
  brute();
  int T = 1;
  cin >> T;
  for (int t = 1, u, v; t <= T; ++t) {
    cin >> u >> v;
    cout << (solve(u, v) ? "YES" : "NO") << '\n';
  }
  return 0;
}
/*
3 12
*/