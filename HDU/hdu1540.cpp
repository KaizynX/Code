/*
 * @Author: Kaizyn
 * @Date: 2020-05-12 14:35:19
 * @LastEditTime: 2020-05-12 14:42:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

int n, m;
int vis[N];

inline void solve() {
  char op;
  int x;
  set<int> st;
  stack<int> stk;
  memset(vis+1, 0, sizeof(int)*n);
  while (m--) {
    cin >> op;
    if (op == 'R') {
      x = stk.top();
      stk.pop();
      vis[x] = 0;
      st.erase(x);
      continue;
    }
    cin >> x;
    if (op == 'D') {
      vis[x] = 1;
      st.insert(x);
      stk.push(x);
    } else {
      if (vis[x]) {
        cout << 0 << endl;
        continue;
      }
      auto it = st.upper_bound(x);
      int r = it == st.end() ? n : *it-1;
      int l = it == st.begin() ? 1 : *(--it)+1;
      cout << r-l+1 << endl;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m) solve();
  return 0;
}