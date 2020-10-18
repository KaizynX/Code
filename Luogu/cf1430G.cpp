/*
 * @Author: Kaizyn
 * @Date: 2020-10-11 18:31:21
 * @LastEditTime: 2020-10-11 19:01:48
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
const int M = 200;

int n, m, resv = INF;
int a[N], resa[N], deg[N], l[N], r[N];
int u[M], v[M], w[M];
vector<int> e[N], re[N];
queue<int> q;

void update() {
  int tmp = 0;
  for (int i = 1, d; i <= m; ++i) {
    d = a[u[i]]-a[v[i]];
    if (d <= 0) return;
    tmp += d*w[i];
  }
  if (tmp < resv) {
    resv = tmp;
    memcpy(resa+1, a+1, sizeof(int)*n);
  }
}

void brute(int x) {
  if (x > n) return update();
  for (int i = l[x]; i <= r[x]; ++i) {
    a[x] = i;
    brute(x+1);
  }
  // a[x] = 0;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> u[i] >> v[i] >> w[i];
    e[u[i]].emplace_back(v[i]);
    re[v[i]].emplace_back(u[i]);
  }
  for (int i = 1; i <= m; ++i) ++deg[u[i]];
  for (int i = 1; i <= n; ++i) if (!deg[i]) q.push(i), l[i] = 0;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int &y : re[x]) {
      l[y] = max(l[y], l[x]+1);
      if (--deg[y] == 0) q.push(y);
    }
  }
  memset(r, 0x3f, sizeof r);
  for (int i = 1; i <= m; ++i) ++deg[v[i]];
  for (int i = 1; i <= n; ++i) if (!deg[i]) q.push(i), r[i] = l[i];
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int &y : e[x]) {
      r[y] = min(r[y], r[x]-1);
      if (--deg[y] == 0) q.push(y);
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) printf("%d:(%d,%d)\n", i, l[i], r[i]);
  #endif
  brute(1);
  for( int i = 1; i <= n; ++i) cout << resa[i] << " \n"[i==n];
  return 0;
}