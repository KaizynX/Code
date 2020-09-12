/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 14:24:35
 * @LastEditTime: 2020-09-07 14:44:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const long long INF = 1e18;
const int N = 6;
const int M = 1e5+7;

template <typename T>
struct MonotonousQueue {
  unsigned head;
  vector<T> q;
  MonotonousQueue() { clear(); }
  void clear() { head = 0; q.clear(); }
  size_t size() { return q.size()-head; }
  bool empty() { return head == q.size(); }
  T front() { return q[head]; }
  T back() { return q.back(); }
  void push_front(const T &x) {/*unsupported*/}
  void push_back(const T &x) { q.push_back(x); }
  void pop_front() { ++head; }
  void pop_back() { q.pop_back(); }
};

int n, m, k, L;
int a[N][M];
long long dp[N][M], sum[N][M];
MonotonousQueue<pair<long long, int>> q[N];

void push(int id, int t) {
  for (int i = 1; i <= n; ++i) if (i != id) {
    long long val = dp[id][t]-sum[i][t];
    while (q[i].size() && q[i].back().first >= val) q[i].pop_back();
    q[i].push_back({val, t});
  }
}

void pop(int id) {
  for (int i = 1; i <= n; ++i) {
    while (q[i].size() && q[i].front().second < id) q[i].pop_front();
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> m >> n >> k >> L;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
      sum[i][j] = sum[i][j-1]+a[i][j];
    }
  }
  push(0, 0);
  for (int j = 1; j <= m; ++j) {
    pop(j-L);
    for (int i = 1; i <= n; ++i)
      dp[i][j] = q[i].front().first+sum[i][j]+k;
    for (int i = 1; i <= n; ++i)
      push(i, j);
  }
  long long res = INF;
  for (int i = 1; i <= n; ++i) res = min(res, dp[i][m]);
  cout << res-k << endl;
  return 0;
}