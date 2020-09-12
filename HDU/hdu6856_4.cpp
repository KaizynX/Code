/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 10:30:03
 * @LastEditTime: 2020-09-02 12:14:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;

template <typename T>
struct Deque {
  unsigned head;
  vector<T> q;
  Deque() { clear(); }
  void clear() { head = 0; q.clear(); }
  size_t size() { return q.size()-head; }
  bool empty() { return head == q.size(); }
  T front() { return q[head]; }
  T back() { return q.back(); }
  void push_front(const T &x) {} // unsupported
  void push_back(const T &x) { q.push_back(x); }
  void pop_front() { ++head; }
  void pop_back() { q.pop_back(); }
};

int n, L, R;
int a[N], sum[N], dp[N];
Deque<int> buf[N<<1], *q = buf+N, mx;

inline int f(int x, int y) {
  if (sum[x] > sum[y]) return 1;
  if (sum[x] < sum[y]) return -1;
  return 0;
}

inline void solve() {
  scanf("%d%d%d", &n, &L, &R);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    sum[i] = sum[i-1]+a[i];
    dp[i] = -n;
  }
  // dp[0] = 0;
  for (int i = L, t; i <= n; ++i) {
    while (mx.size() && mx.front() < i-R) mx.pop_front();
    if (dp[i-L] > -n) {
      t = dp[i-L];
      while (q[t].size() && q[t].front() < i-R) q[t].pop_front();
      while (q[t].size() && sum[q[t].back()] >= sum[i-L]) q[t].pop_back();
      q[t].push_back(i-L);
      while (mx.size() && dp[mx.back()] <= t) mx.pop_back();
      mx.push_back(i-L);
    }
    for (int d = 0; d < 2; ++d) {
      t = dp[mx.front()]-d;
      while (q[t].size() && q[t].front() < i-R) q[t].pop_front();
      if (q[t].size()) dp[i] = max(dp[i], dp[q[t].front()]+f(i, q[t].front()));
    }
  }
  printf("%d\n", dp[n]);
}

inline void clear() {
  mx.clear();
  for (int i = 0; i <= n; ++i) q[dp[i]].clear();
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    solve();
    clear();
  }
  return 0;
}