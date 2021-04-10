/*
 * @Author: Kaizyn
 * @Date: 2021-04-10 09:00:19
 * @LastEditTime: 2021-04-10 09:23:24
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;

int n;
string a[N];

bool cmp(string &x, string &y) {
  return x.size() == y.size() ? x < y : x.size() < y.size();
}

string add(string x) {
  for (int i = (int)x.size()-1; i >= 0; i--) {
    x[i]++;
    if (x[i] > '9') x[i] -= 10;
    else break;
  }
  if (x[0] > '9') {
    x[0] -= 10;
    x = "1"+x;
  }
  return x;
}

inline int solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 2; i <= n; ++i) {
    if (cmp(a[i-1], a[i])) continue;
    string pre = a[i-1].substr(0, a[i].size());
    string suf = a[i-1].substr(a[i].size());
    int d = a[i-1].size()-a[i].size();
    if (pre < a[i]) {
      a[i] += string(d, '0');
      res += d;
    } else if (pre > a[i]) {
      a[i] += string(d+1, '0');
      res += d+1;
    } else {
      if (suf.empty() || suf == string(d, '9')) {
        a[i] += string(d+1, '0');
        res += d+1;
      } else {
        a[i] += add(suf);
        res += d;
      }
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << '\n';
  }
  #endif
  return res;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    int res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}