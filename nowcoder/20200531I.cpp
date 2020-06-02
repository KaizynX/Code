/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 16:11:24
 * @LastEditTime: 2020-05-31 16:17:04
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

int n;
int a[N], b[N];
vector<int> stk, pre, suf, res;

inline void solve() {
  stk.clear();
  pre.clear();
  suf.clear();
  res.clear();

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i-1] = a[i];
  }
  for (int i = 1; i <= n; ++i) {
    stk.emplace_back(i);
    if (a[i] > b[i]) {
      pre.insert(pre.end(), stk.begin(), stk.end());
      stk.clear();
    } else if (a[i] < b[i]) {
      reverse(stk.begin(), stk.end());
      suf.insert(suf.end(), stk.begin(), stk.end());
      stk.clear();
    }
  }
  res = pre;
  res.insert(res.end(), stk.begin(), stk.end());
  reverse(suf.begin(), suf.end());
  res.insert(res.end(), suf.begin(), suf.end());
  for (int &i : res) cout << i << " ";
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}