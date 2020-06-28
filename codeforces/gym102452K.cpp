/*
 * @Author: Kaizyn
 * @Date: 2020-06-25 22:09:21
 * @LastEditTime: 2020-06-26 10:04:40
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 8e2+7;
const int M = 5e4+7;

struct Node {
  vector<int> v;
  void insert(const int &c) {
    v.emplace_back(c);
  }
  void init() {
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
  }
  int top() {
    return v.empty() ? INF : v.back();
  }
  void pop() {
    v.pop_back();
  }
};

int n, m;
int d[N];
Node alg[N], sof[N];
int pos_v[N], neg_v[N];
deque<int> pos_q;

inline void solve() {
  cin >> n >> m;
  for (int i = 2; i <= n; ++i) {
    cin >> d[i];
    d[i] += d[i-1];
  }
  for (int i = 1, x, c; i <= m; ++i) {
    cin >> x >> c;
    alg[x].insert(c);
  }
  for (int i = 1, x, c; i <= m; ++i) {
    cin >> x >> c;
    sof[x].insert(c);
  }
  for (int i = 1; i <= n; ++i) {
    alg[i].init();
    sof[i].init();
  }
  long long res = 0;
  for (int i = 1, pa, ps, cur, neg_q; i <= m; ++i) {
    cur = INF;
    neg_q = 1;
    pos_q.clear();
    for (int i = 1; i <= n; ++i) {
      pos_v[i] = sof[i].top()+d[i];
      neg_v[i] = sof[i].top()-d[i];
      while (pos_q.size() && pos_v[i] <= pos_v[pos_q.back()]) pos_q.pop_back();
      pos_q.push_back(i);
    }
    for (int i = 1, val; i <= n; ++i) {
      while (pos_q.size() && pos_q.front() < i) pos_q.pop_front();
      val = alg[i].top()-d[i]+pos_v[pos_q.front()];
      if (val < cur) {
        cur = val;
        pa = i;
        ps = pos_q.front();
      }
      if (neg_v[i] < neg_v[neg_q]) neg_q = i;
      val = alg[i].top()+d[i]+neg_v[neg_q];
      if (val < cur) {
        cur = val;
        pa = i;
        ps = neg_q;
      }
    }
    alg[pa].pop();
    sof[ps].pop();
    cout << (res += cur) << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}