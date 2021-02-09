/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 15:53:39
 * @LastEditTime: 2021-02-03 16:08:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

string a, b, k;

void update(int i, char c, int j) {
  if (c == '3' || c == '7') {
    if (j >= (int)b.size() || c != b[j]) return;
    ++j;
  }
  int r = ((int)a.size()-i-1)-((int)b.size()-j);
  if (r < 0) return;
  string t = a.substr(0, i);
  t += c;
  t += string(r, '0');
  t += b.substr(j);
  if (k.empty()) k = t;
  else k = min(k, t);
}

inline void solve() {
  cin >> a >> b;
  if (b.size() > a.size() || (a.size() == b.size() && b > a)) {
    cout << b << endl;
    return;
  }
  if (a.size() == b.size()) {
    a = "0"+a;
  }
  for (int i = 0, j = 0; i < (int)a.size(); ++i) {
    // k[i] > a[i]
    for (char c = a[i]+1; c <= '9'; ++c) update(i, c, j);
    if (a[i] == '3' || a[i] == '7') {
      if (j >= (int)b.size() || a[i] != b[j]) break; 
      ++j;
    }
  }
  cout << k << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}