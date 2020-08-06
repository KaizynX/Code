/*
 * @Author: Kaizyn
 * @Date: 2020-07-13 13:45:02
 * @LastEditTime: 2020-07-13 14:05:10
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 150000+7;
const int M = 40000+7;

struct Node {
  int val, id, time;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.val > rhs.val;
  }
};

int n, m;
int a[N], b[M], add[N];
priority_queue<Node> q; // 小根堆
priority_queue<pii> qaq; // 大根堆

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];

  for (int i = 1; i <= n; ++i) {
    qaq.push({a[i], i});
  }
  b[m+1] = INF;
  for (int i = 1; i <= m+1; ++i) {
    #ifdef DEBUG
    cout << i << " " << b[i] << endl;
    #endif
    while (q.size() && q.top().val < b[i]) {
      #ifdef DEBUG
      cout << "q->qaq:" << q.top().val << " " << q.top().id << " " << q.top().time << endl;
      #endif
      ++add[q.top().id-i+2];
      --add[max(1, q.top().id-q.top().time+2)];
      qaq.push({q.top().val, q.top().id});
      q.pop();
    }
    while (qaq.size() && qaq.top().first >= b[i]) {
      #ifdef DEBUG
      cout << "qaq->q:" << qaq.top().first << " " << qaq.top().second << endl;
      #endif
      q.push(Node{qaq.top().first, qaq.top().second, i});
      qaq.pop();
    }
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    add[i] += add[i-1];
    res += add[i] >= m;
  }
  cout << res << endl;
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