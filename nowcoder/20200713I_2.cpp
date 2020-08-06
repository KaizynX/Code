/*
 * @Author: Kaizyn
 * @Date: 2020-07-13 16:25:16
 * @LastEditTime: 2020-07-13 21:41:05
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef pair<long long, int> pli;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e2+7;
const int S = 3e5+7;

int n, m;
long long dis[S];
vector<pii> e[S];
priority_queue<pli, vector<pli>, greater<pli>> q;

inline int change(const int &x, const int &y) {
  return x*(n+1)+y;
}

inline long long solve() {
  memset(dis, -1, sizeof dis);

  for (int i = 1, l, r, c; i <= m; ++i) {
    char dir;
    cin >> l >> r >> dir >> c;
    if (dir == 'L') {
      // (l, r)->(l, r+1)
      e[change(l, r)].emplace_back(c, change(l, r-1));
      e[change(l, r-1)].emplace_back(c, change(l, r));
    } else {
      // (l, r-1)->(l-1, r-1)
      e[change(l, r-1)].emplace_back(c, change(l-1, r-1));
      e[change(l-1, r-1)].emplace_back(c, change(l, r-1));
    }
  }
  for (int i = 1; i <= n; ++i) {
    dis[change(i, n)] = 0;
    q.push({0, change(i, n)});
  }
  while (q.size()) {
    int u = q.top().second;
    long long du = q.top().first;
    q.pop();
    if (du > dis[u]) continue;
    if (u <= n) return du;
    for (const pii &edge : e[u]) {
      int v = edge.second;
      int c = edge.first;
      if (dis[v] == -1 || dis[u]+c < dis[v]) {
        dis[v] = dis[u]+c;
        q.push({dis[v], v});
      }
    }
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) cout << solve() << endl;
  return 0;
}