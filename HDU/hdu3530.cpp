/*
 * @Author: Kaizyn
 * @Date: 2020-09-07 10:43:05
 * @LastEditTime: 2020-09-07 10:50:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

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

int n, l, r;
int a[N];
MonotonousQueue<int> minv, maxv;

inline void solve() {
  minv.clear();
  maxv.clear();
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int res = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    while (minv.size() && a[minv.back()] >= a[i]) minv.pop_back();
    minv.push_back(i);
    while (maxv.size() && a[maxv.back()] <= a[i]) maxv.pop_back();
    maxv.push_back(i);
    while (a[maxv.front()]-a[minv.front()] > r) {
      while (minv.size() && minv.front() <= j) minv.pop_front();
      while (maxv.size() && maxv.front() <= j) maxv.pop_front();
      ++j;
    }
    if (a[maxv.front()]-a[minv.front()] >= l) res = max(res, i-j+1);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> l >> r) solve();
  return 0;
}