/*
 * @Author: Kaizyn
 * @Date: 2020-09-08 23:39:34
 * @LastEditTime: 2020-09-08 23:43:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4+7;

int n;
int a[N], vis[N];
queue<int> q;

int ask(int x, int y) {
  int res;
  cout << "? " << x << " " << y << endl;
  cin >> res;
  return res;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) q.push(i);
  while (q.size() > 1) {
    int x = q.front(); q.pop();
    int y = q.front(); q.pop();
    int u = ask(x, y);
    int v = ask(y, x);
    if (u > v) swap(u, v), swap(x, y);
    a[y] = v;
    vis[v] = 1;
    q.push(x);
  }
  int x = q.front();
  for (int i = 1; i <= n; ++i) if (!vis[i]) a[x] = i;
  cout << "!";
  for (int i = 1; i <= n; ++i) cout << " " << a[i];
  cout << endl;
  return 0;
}