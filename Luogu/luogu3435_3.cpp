/*
 * @Author: Kaizyn
 * @Date: 2021-08-10 10:02:26
 * @LastEditTime: 2021-08-10 10:05:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

template <typename T>
struct MonotonousQueue {
  unsigned head;
  vector<T> q;
  MonotonousQueue() { clear(); }
  T& operator [](const int &i) { return q[head+i];}
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

vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

int n;
vector<pii> add[N];
MonotonousQueue<pii> q;
string s;

inline void solve() {
  cin >> n >> s;
  auto z = z_function(s);
  ll res = 0;
  for (int i = 1; i < n; ++i) if (z[i]) {
    // z[i] >= n-i, n <= z[i]+i
    int j = min(i*2, z[i]+i);
    add[i+1].emplace_back(i, j+1);
  }
  for (int i = 1; i <= n; ++i) {
    while (q.size() && q.front().second < i) q.pop_front();
    for (auto pr : add[i]) {
      while (q.size() && q.back().first < pr.first) q.pop_back();
      q.push_back(pr);
    }
    if (q.size()) res += q.front().first;
  }
  cout << res << '\n';
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