/*
 * @Author: Kaizyn
 * @Date: 2020-10-10 23:57:47
 * @LastEditTime: 2020-10-11 00:42:59
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 555;

int n;
int a[N], b[N];
vector<int> vec[N];

void print(int t) {
  cout << t-1 << endl;
  for (int i = 1; i < t; ++i) {
    vector<int> &r = vec[i];
    cout << r.size()-1;
    for (int i = 1; i < (int)r.size(); ++i) cout << " " << r[i]-r[i-1];
    cout << endl;
  }
}

void magic(int t) {
  vector<int> &r = vec[t];
  int i = 1;
  r.emplace_back(n+1);
  for (int j = (int)r.size()-2; j >= 0; --j) {
    for (int k = r[j]; k < r[j+1]; ++k) {
      b[i++] = a[k];
    }
  }
  memcpy(a+1, b+1, sizeof(int)*n);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int t = 1; t <= n+1; ++t) {
    vector<int> &r = vec[t];
    r.clear();
    r.emplace_back(1);
    for (int i = 2; i <= n; ++i) {
      if (a[i] == a[i-1]+1) continue;
      else r.emplace_back(i);
    }
    if (r.size() == 1) return print(t);
    magic(t);
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