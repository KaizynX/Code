#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int n, m, A, B;
int dp[N], deg[N], vis[N], col[N];
vector<int> e[N], re[N];

bool check() {
  queue<int> q;
  int k = 0, flag = 1;
  for (int i = 1; i <= n; ++i) {
    re[i].clear();
    deg[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int &j : e[i]) {
      re[j].emplace_back(i);
      ++deg[i];
    }
  }
  for (int i = 1; i <= n && flag; ++i) if (e[i].empty()) {
    col[i] = ++k;
    q.push(i);
    while (q.size() && flag) {
      int u = q.front();
      q.pop();
      for (int &v : re[u]) {
        if (!col[v]) col[v] = col[u];
        if (col[v] != col[u]) flag = 0;
        if (--deg[v] == 0) q.push(v);
      }
    }
  }
  return flag;
}

void rebuild() {
  queue<int> q;
  q.push(A);
  vis[A] = 1;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int &v : e[u]) {
      if (!vis[v]) {
        q.push(v);
        vis[v] = 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) if (vis[i]) {
    for (int &j : e[i]) if (vis[j]) {
      re[i].emplace_back(j);
      ++deg[j];
    }
  }
}

int calc() {
  rebuild();
  queue<int> q;
  dp[A] = 1;
  q.push(A);
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int &v : re[u]) {
      dp[v] += dp[u];
      if (--deg[v] == 0) q.push(v);
    }
  }
  return dp[B];
}

signed main() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
  }
  cin >> A >> B;
  cout << calc() << " " << (check() ? "Yes" : "No") << endl;
  return 0;
}