/*
 * @Author: Kaizyn
 * @Date: 2020-05-10 19:57:14
 * @LastEditTime: 2020-05-10 21:34:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int minv[N], endv[N];
string s[N];
vector<int> neg, pos;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> s[i];
  int sum = 0, val = 0;
  for (int i = 1; i <= n; ++i) {
    for (const char &c : s[i]) {
      endv[i] += (c == '(' ? 1 : -1);
      minv[i] = min(minv[i], endv[i]);
    }
    sum += endv[i];
    if (minv[i] >= 0) {
      val += endv[i];
    } else if (endv[i] >= 0) {
      pos.emplace_back(i);
    } else if (minv[i] < endv[i]) {
      neg.emplace_back(i);
    }
  }
  if (sum != 0) return void(cout << "No" << endl);
  sort(pos.begin(), pos.end(), [&](const int &x, const int &y) {
      return minv[x] > minv[y];
  });
  for (const int &i : pos) {
    if (val < -minv[i]) return void(cout << "No" << endl);
    val += endv[i];
  }
  sort(neg.begin(), neg.end(), [&](const int &x, const int &y) {
      return minv[x] < minv[y];
  });
  for (const int &i : neg) {
    if (val < -minv[i]) return void(cout << "No" << endl);
    val += endv[i];
  }
  cout << "Yes" << endl;
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